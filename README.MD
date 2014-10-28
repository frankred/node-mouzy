Mouzy
===
Mouzy is a node module to control your mouse cursor. Currently only Windows is supported.

Install
==
```git clone https://github.com/frankred/node-mouzy.git```

```cd node-mouzy```

```node-gyp configure```

```node-gyp build```


Support
==
- Windows

Usage
==
Include
```javascript
var mouzy = require("./node-mouzy");
```

Move cursor to screen position 200px/200px.
```javascript
mouzy.setPosition(200, 200);
```

Move cursor by delta.
```javascript
mouzy.move(323, -44);
```

Simulate mouse click.
```javascript
mouzy.click();
``` 
