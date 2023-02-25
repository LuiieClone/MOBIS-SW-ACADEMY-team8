from flask import Flask
from ctypes import cdll
import ctypes

libc=cdll.LoadLibrary('./libgpio.so')
'''
input('Continue?')
result=libc.getButton(23)
print(ctypes.c_char_p(result).value.decode('utf-8'))
'''
app=Flask(__name__)

@app.route('/')
@app.route('/ledon')
def ledon():
    print("ledon")
    result=libc.ledon(18)
    py_string=ctypes.c_char_p(result).value.decode('utf-8')
    print(py_string)
    return py_string

@app.route('/ledoff')
def ledoff():
    print("ledoff")
    result=libc.ledoff(18)
    py_string=ctypes.c_char_p(result).value.decode('utf-8')
    print(py_string)
    return py_string

@app.route('/swstate')
def swstate():
    print("swstate")
    result=libc.getButton(24)
    py_string=ctypes.c_char_p(result).value.decode('utf-8')
    print(py_string)
    return py_string

if __name__=='__main__':
    app.run("0.0.0.0", port=80)
