# SilentLauncher
## Get
[Download](https://github.com/sanyabeast/silent_launcher/raw/master/Release/silent_launcher.exe)

## Use

### Silent launch
Name file usering pattern:
```
~%your_command%.exe
```

### Explicit launch
Name file usering pattern:
```
$%your_command%.exe
```
### Characters aliases
Use these aliases to put forbidden characters inside your command

- ```[fsh]``` : ```/```
- ```[bsh]``` : ```\```
- ```[qot]``` : ```"```
- ```[arx]``` : ```*```
- ```[lth]``` : ```<```
- ```[gth]``` : ```>```
- ```[cln]``` : ```:```
- ```[bar]``` : ```|```
- ```[qst]``` : ```?```

### Examples
silently launches some_actions.bat alongside exe-file`s location:
```
~some_actions.bat.exe
```
Explicitly launches Windows Explorer for exe-file`s parent directory:
```
@explorer ...exe
```
silently running 'node ./scripts/server.js' command
```
~node .[fsh]scripts[fsh]server.js.exe
```
