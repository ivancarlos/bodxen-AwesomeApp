
```{bash}
boden new -n AwesomeApp
boden build -p android --config Debug
boden build -a arm64-v8a -p android --config Debug
```


```{bash}
../boden build -a arm64-v8a -p android --config Debug &&
scp ./build/android/arm64-v8a/AndroidStudio/Debug/AwesomeApp/build/outputs/apk/debug/AwesomeApp-debug.apk dev:www
```

