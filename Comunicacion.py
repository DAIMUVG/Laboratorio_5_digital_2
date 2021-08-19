import serial
import time
from Adafruit_IO import Client, RequestError, Feed
puerto = serial.Serial('COM2',9600)

ADAFRUIT_IO_KEY = "aio_SCXG97B2AK8fthSDvRAWhE5VsLL7"
ADAFRUIT_IO_USERNAME = "Dylan_Ixcayau"
aio = Client(ADAFRUIT_IO_USERNAME, ADAFRUIT_IO_KEY)


while 1:
    
    ValorPORTD_feed = aio.feeds('holi')
    ValorPORTD_data = aio.receive('holi').value


    #puerto.write(chr(int(ValorPORTD_data)).encode())
    time.sleep(2)
