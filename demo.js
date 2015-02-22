
// This code is public domain
// (but note, that the led-matrix library this depends on is GPL v2)

var board = require('./main')

var boardHeight = 16

board.start(boardHeight)

function fade() {
  var v = 0
  var inc = true
  setInterval(function () {
    board.fill(v, v, v)
    if (inc) {
      v++
      if (v >= 255) inc = false
    }
    else {
      v--
      if (v <= 0) inc = true
    }
  }, 1)
}

function strobe() {
  setInterval(function () {
    board.fill(255, 255, 255)
    setTimeout(function() {
      board.clear()
    }, 5)
  }, 125)
}

function police() {
  var odd = true
  setInterval(function () {
    if (odd) {
      board.fill(255, 0, 0)
    }
    else {
      board.fill(0, 0, 255)
    }
    odd = !odd
  }, 160)
}


fade()
