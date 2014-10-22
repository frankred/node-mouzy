var mouse = require('./build/Release/mouzy');

// Move cursor 100 pixel to the right and 200 pixel down
// mouse.move(deltaX, deltaY);
mouse.move(100,200);

// Move cursor 100 pixel to the left and 20 pixel up
mouse.move(-50,-20);

// Reset cursor position to (0,0) the upper left corner
mouse.move(Number.NEGATIVE_INFINITY,Number.NEGATIVE_INFINITY);
mouse.move(800, 800);	// Cursor is now at absolute position 800,800

// Click
mouse.click();