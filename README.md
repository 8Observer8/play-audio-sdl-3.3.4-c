# Play Audio SDL3 (C)

**Demo in the browser:** https://8observer8.github.io/examples/sdl3/play-audio-sdl-3.3.4-c/

**EXE for Windows 10, 64-bit:** [play-audio-sdl3-3.3.4-c-exe.zip](https://www.dropbox.com/scl/fi/fdgpxseyi878pwm4c61l2/play-audio-sdl-3.3.4-c-exe.zip?rlkey=nvcmuspr21t1zurd1yb9l00q1&st=l0c5pxyt&raw=1)
- Zip size: 1.58 MB
- Unzipped: 3.43 MB

---

## File Sizes

**WASM ( built with Emscripten 4.0.15):**

- `index.html` — 1.32 KB
- `app.js` — 183 KB
- `app.wasm` — 1.53 MB
- **Total:** 1.71 MB

**EXE (built with MinGW GCC 11.2):**

- EXE — 53.5 KB
- `SDL3.dll` (v3.3.4) — 2.65 MB
- `SDL3_mixer.dll`(v3.1.0) — 304 KB
- Assets ([picked-coin-echo-2.wav](https://opengameart.org/content/picked-coin-echo-2)) — 444 KB
- **Total:** 3.43 MB

---

## Tools to Build the EXE

- [MinGW GCC 11.2](https://github.com/brechtsanders/winlibs_mingw/releases/download/11.2.0-14.0.0-9.0.0-ucrt-r7/winlibs-x86_64-posix-seh-gcc-11.2.0-mingw-w64ucrt-9.0.0-r7.zip) (zip - 178 MB, unzipped - 671 MB)
- [SDL3-3.3.4-win32-x64.zip](https://www.dropbox.com/scl/fi/6zojft1cdj2kzpljj2j5c/SDL3-3.3.4-win32-x64.zip?rlkey=lxvf4lzsfiv846ajpnic49s5j&st=3ukhpza9&raw=1) (zip - 0.98 MB, unzipped - 2.4 MB)
- [SDL3-devel-3.3.4-mingw.zip](https://www.dropbox.com/scl/fi/njib4pzrkuplxkomqihhg/SDL3-devel-3.3.4-mingw.zip?rlkey=69bhrsjx2w4j4ca1rc5arfbq5&st=x041deaf&raw=1) (zip - 2.35 MB, unzipped - 8.55 MB)
- [SDL3_mixer-3.1.0-win32-x64.zip](https://www.dropbox.com/scl/fi/yeiqe8wg41uw9u52qdmh7/SDL3_mixer-3.1.0-win32-x64.zip?rlkey=4teql5s5da9pn4eaz630idk21&st=hm6whpnj&raw=1) (zip - 138 KB, unzipped - 304 KB)
- [SDL3_mixer-devel-3.1.0-mingw.zip](https://www.dropbox.com/scl/fi/kpnoygzarw3o0jvfs06vs/SDL3_mixer-devel-3.1.0-mingw.zip?rlkey=y4ssud1webh3fvu103hbsgecp&st=htx3l1rh&raw=1) (zip - 184 KB, unzipped - 513 KB)

---

## Tools to Build WebAssembly

- [Emscripten 4.0.15](https://emscripten.org/docs/getting_started/downloads.html) (1.82 GB)
- [SDL3-devel-3.3.4-wasm.zip](https://www.dropbox.com/scl/fi/ogokwxxc64f0lgf01q9oe/SDL3-devel-3.3.4-wasm.zip?rlkey=p2ggy9ynptdlbroi9ixaj1d2c&st=k2fyu1tk&raw=1) (zip - 1.21 MB, unzipped - 5.2 MB)
- [SDL3_mixer-devel-3.1.0-wasm.zip](https://www.dropbox.com/scl/fi/0e5cqe5g62idz067ihi8m/SDL3_mixer-devel-3.1.0-wasm.zip?rlkey=099fnwa4mcb5qexntzmwsfai7&st=z1lj7bjo&raw=1) (zip - 163 KB, unzipped - 444 KB)

---

## How to Build EXE (Windows)

- Add [MinGW GCC 11.2](https://github.com/brechtsanders/winlibs_mingw/releases/download/11.2.0-14.0.0-9.0.0-ucrt-r7/winlibs-x86_64-posix-seh-gcc-11.2.0-mingw-w64ucrt-9.0.0-r7.zip) `bin` folder to your `PATH`.
- Add [SDL3-3.3.4-win32-x64.zip](https://www.dropbox.com/scl/fi/6zojft1cdj2kzpljj2j5c/SDL3-3.3.4-win32-x64.zip?rlkey=lxvf4lzsfiv846ajpnic49s5j&st=3ukhpza9&raw=1) folder to your `PATH`.
- Add [SDL3_mixer-3.1.0-win32-x64.zip](https://www.dropbox.com/scl/fi/yeiqe8wg41uw9u52qdmh7/SDL3_mixer-3.1.0-win32-x64.zip?rlkey=4teql5s5da9pn4eaz630idk21&st=hm6whpnj&raw=1) folder to your `PATH`.
- Configure paths in `config-web.bat` for your SDL3 libraries.
- From the project root, run:

```bat
config-exe
build-exe
run-exe
```

## How to Build WebAssembly

1. Set up [Emscripten 4.0.15](https://emscripten.org/docs/getting_started/downloads.html) and Node.js
2. Install http-server globally:

```bat
npm i http-server -g
```

3. Configure paths in `config-web.bat` for your SDL3 libraries.
4. From the project root, run:

```bat
config-web
build-web
http-server -c-1
```

5. Open your browser and go to http://localhost:8080 to run the app locally.

> Note: You can also run the WASM app on Android via Wi-Fi using http-server. After starting the server, it will show local URL addresses — just type one into your mobile browser.
