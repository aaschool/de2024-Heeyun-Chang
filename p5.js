<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Motion Sensor and LED Status</title>
  <script src="https://cdnjs.cloudflare.com/ajax/libs/p5.js/1.4.0/p5.js"></script>
  <script>
    let motionStatus = 'No Motion Detected';
    let ledStatus = 'LED OFF';

    function setup() {
      createCanvas(400, 200);
    }

    function draw() {
      background(220);
      textSize(20);
      textAlign(CENTER, CENTER);
      text(motionStatus, width / 2, height / 2 - 20);
      text(ledStatus, width / 2, height / 2 + 20);
    }

    function updateMotion(status) {
      motionStatus = status;
    }

    function updateLED(status) {
      ledStatus = status;
    }
  </script>
</head>
<body>
  <h1>Motion Sensor and LED Status</h1>
  <div id="status"></div>
  <script>
    function updateStatus(status) {
      document.getElementById('status').innerText = status;
    }

    setInterval(() => {
      fetch('/status')
        .then(response => response.json())
        .then(data => {
          updateStatus(`Motion: ${data.motion}, LED: ${data.led}`);
          updateMotion(data.motion);
          updateLED(data.led);
        });
    }, 1000);
  </script>
</body>
</html>
