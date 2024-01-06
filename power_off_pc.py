import requests

# Ganti dengan Auth Token dan ID virtual pin Anda
auth_token = "b3yRyPOjlew0QcWmb0AUUlZSCK8rHzyU"
virtual_pin_id = "V1"

# Ganti dengan nilai string yang ingin Anda kirimkan
nilai_string_yang_dikirim = "OFF"

# URL untuk mengirimkan nilai string ke virtual pin
url = "https://blynk.cloud/external/api/update?token=b3yRyPOjlew0QcWmb0AUUlZSCK8rHzyU&v1=OFF"

# Kirim permintaan HTTP
response = requests.get(url)

# Cek apakah permintaan berhasil
if response.status_code == 200:
    print("Nilai String berhasil dikirim ke Blynk.")
else:
    print("Gagal mengirim nilai String ke Blynk. Kode status:", response.status_code)
