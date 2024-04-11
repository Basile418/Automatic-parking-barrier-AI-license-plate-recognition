from flask import Flask, request
import os

app = Flask(__name__)

@app.route('/upload_photo.php', methods=['POST'])
def upload_photo():
    # Check for the existence of the image
    folder = 'C:/Users/basil/Desktop/test_plaque_fr'
    img_received = 0
    
    while img_received == 0:
        files = os.listdir(folder)
        n = len(files)
        img_received = 0
        
        for i in range(n):
            if files[i] == "received_photo.jpg":
                img_received = 1
                print('Folder full 1')
        
        print('img_received=', img_received)
        
        if img_received == 0:
            # Start uploading the image if it doesn't exist
            photo_data = request.get_data()
            
            # Save the photo to a specific file
            with open('C:/Users/basil/Desktop/test_plaque_fr/photo_received.jpg', 'wb') as f:
                f.write(photo_data)

            return 'Photo received successfully'
        else:
            return 'Folder full 2'


if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')
