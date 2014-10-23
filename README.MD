Mouzy
===
Mouzy is a node module to control your mouse cursor. Currently only Windows is supported.

Install
==
```npm install -S "git+https://github.com/frankred/node-mouzy.git"```

Support
==
- Windows

Usage
==
Include
```
var mouzy = require("mouzy");
```

Move cursor to screen position 200px/200px.
```
mouzy.setPosition(200, 200);
```

Move cursor by delta.
```
mouzy.move(323, -44);
```

Simulate mouse click.
```
mouzy.click();
``` 
