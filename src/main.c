#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <stdio.h>

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

static MIX_Mixer *mixer = NULL;
static MIX_Audio *audio = NULL;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv)
{
    // --- Disable unwanted decoders ---
    SDL_SetHint("SDL_MIXER_DISABLE_DRFLAC", "1");
    SDL_SetHint("SDL_MIXER_DISABLE_DRMP3", "1");

    // --- Init SDL ---
    if (!SDL_Init(SDL_INIT_VIDEO))
    { // you used SDL_INIT_VIDEO in python
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    // --- Create window and renderer ---
    const char *title = "Play a sound by click using SDL3 C";
    if (!SDL_CreateWindowAndRenderer(title, 300, 300, 0, &window, &renderer))
    {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    SDL_SetRenderVSync(renderer, 1);

    // --- Print SDL versions ---
    printf("Compiled SDL version: %d.%d.%d\n",
        SDL_MAJOR_VERSION,
        SDL_MINOR_VERSION,
        SDL_MICRO_VERSION);
    // Get the version of the SDL library linked at runtime
    int v = SDL_GetVersion();
    printf("Linked SDL3 version:  %d.%d.%d\n", SDL_VERSIONNUM_MAJOR(v),
        SDL_VERSIONNUM_MINOR(v), SDL_VERSIONNUM_MICRO(v));

    // --- SDL3_mixer version ---
    v = MIX_Version();
    int major = SDL_VERSIONNUM_MAJOR(v);
    int minor = SDL_VERSIONNUM_MINOR(v);
    int micro = SDL_VERSIONNUM_MICRO(v);
    printf("SDL3_mixer version:   %d.%d.%d\n", major, minor, micro);

    // --- Init mixer ---
    if (!MIX_Init())
    {
        SDL_Log("MIX_Init failed: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    mixer = MIX_CreateMixerDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, NULL);
    if (!mixer)
    {
        SDL_Log("Couldn't create mixer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    // --- Print mixer spec ---
    SDL_AudioSpec mspec;
    MIX_GetMixerFormat(mixer, &mspec);
    printf("Mixer format: %s, %d channels, %d Hz\n",
        SDL_GetAudioFormatName(mspec.format),
        mspec.channels,
        mspec.freq);

    // --- Print available decoders ---
    printf("Available MIXER decoders:\n");

    int ndec = MIX_GetNumAudioDecoders();
    if (ndec < 0)
    {
        printf(" - [error: %s]\n", SDL_GetError());
    }
    else if (ndec == 0)
    {
        printf(" - [none]\n");
    }
    else
    {
        for (int i = 0; i < ndec; i++)
        {
            printf(" - %s\n", MIX_GetAudioDecoder(i));
        }
    }

    // --- Load WAV audio file ---
    const char *audiofile = "./assets/audio/picked-coin-echo-2.wav";
    audio = MIX_LoadAudio(mixer, audiofile, false);

    if (!audio)
    {
        SDL_Log("Failed to load '%s': %s", audiofile, SDL_GetError());
    }
    else
    {
        SDL_AudioSpec aspec;
        MIX_GetAudioFormat(audio, &aspec);

        printf("%s: %s, %d channel%s, %d Hz\n",
            audiofile,
            SDL_GetAudioFormatName(aspec.format),
            aspec.channels,
            (aspec.channels == 1 ? "" : "s"),
            aspec.freq);
    }

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_QUIT)
    {
        return SDL_APP_SUCCESS;
    }
    else if (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN)
    {
        if (!MIX_PlayAudio(mixer, audio))
        {
            SDL_Log("Failed to play audio: %s", SDL_GetError());
        }
    }

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate)
{
    SDL_SetRenderDrawColor(renderer, 210, 220, 210, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    if (audio)
    {
        MIX_DestroyAudio(audio);
        audio = NULL;
    }

    if (mixer)
    {
        MIX_DestroyMixer(mixer);
        mixer = NULL;
    }

    if (renderer)
    {
        SDL_DestroyRenderer(renderer);
        renderer = NULL;
    }

    if (window)
    {
        SDL_DestroyWindow(window);
        window = NULL;
    }

    MIX_Quit();
    SDL_Quit();
}
