const map = L.map('map').setView([26.4207, 50.0888], 13);

L.tileLayer(
    'https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png'
).addTo(map);

const marker = L.marker([26.4207, 50.0888]).addTo(map);

async function updateLocation() {

    const response = await fetch("http://localhost:8000");

    const data = await response.json();

    marker.setLatLng([26.4207, 50.0888]);

    map.panTo([26.4207, 50.0888]);
}

setInterval(updateLocation, 2000);
