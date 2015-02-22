
// This code is public domain
// (but note, that the led-matrix library this depends on is GPL v2)

// You'll need to install 'canvas' for this to work
// 'canvas' depends on cairo and other things
// Run:
// sudo apt-get install libcairo2-dev libjpeg8-dev libpango1.0-dev libgif-dev build-essential g++
// Then 
// npm install canvas

var Canvas = require('canvas')
var board = require('./main')

var width = 32
var height = 16

board.start(height)

var canvas = new Canvas(width, height)
var ctx = canvas.getContext('2d');

// Verdana looks decent at low resolutions
ctx.font = "11px Verdana";

setInterval(function() {
	var now = new Date()
	var minutes = now.getMinutes().toString()
	var seconds = now.getSeconds().toString()
	if (minutes.length === 1) minutes = '0' + minutes
	if (seconds.length === 1) seconds = '0' + seconds
	var str = '' + minutes + ':' + seconds

	ctx.fillStyle = "black"
	ctx.fillRect(0, 0, 32, 16)

	ctx.fillStyle = "#00FF70"
	ctx.fillText(str, 0, 8)

	board.drawCanvas(ctx, width, height)

}, 1000)


// JS logo :)
// ctx.fillStyle = "#f3df49"
// ctx.fillRect(0, 0, 32, 16)
// ctx.fillStyle = "#2e2e2c"
// ctx.font = "10px Arial";
// ctx.fillText("JS", 20, 15)
// board.drawCanvas(ctx, width, height)
// setInterval(function(){}, 1000)