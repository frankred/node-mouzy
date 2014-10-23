// What platform you're running on: 'darwin', 'freebsd', 'linux', 'sunos' or 'win32'
switch (process.platform) {
    case "win32":
        module.exports = require('./build/Release/mouzy_win.node');
        break;
    case "darwin":
    case "linux":
    case "freebsd":
    case "sunos":
    default:
        module.exports = {
            move: function () {
                throw new Error('Platform ' + process.platform + ' not supported');
            },
            click: function () {
                throw new Error('Platform ' + process.platform + ' not supported');
            }
        };
        break;
}
