# The information about how to structure the API Commands can be found here:
# https://www.loxone.com/dede/wp-content/uploads/sites/2/2021/10/API-Commands.pdf

import requests
from requests.auth import HTTPBasicAuth
import time

local_url= "http://192.168.0.69/"
serial_number = "504F94A1242E"

username = "Test"
password = "Test123"

#Put the name of your Virtual Text Input between the ""
virtual_text_input = "ExampleVTI"

basic = HTTPBasicAuth(username,password)

external_url = f"http://dns.loxonecloud.com/{serial_number}"
resolved_external_url = (requests.get(external_url)).url

command_base = f"dev/sps/io/{virtual_text_input}/"

lights_on = "SET(Lico;On;Pulse)"
lights_off= "SET(Lico;Off;Pulse)"
toggle_switch = "SET(Sw;Tg;Pulse)"

switch_trigger = "SET(Sw;Tg;Pulse)"

#Execute a command on the local network

def execute_local_command(command):
    command = local_url + command_base + command
    return print(requests.get(command,auth =basic))

# execute_local_command(lights_off)

# time.sleep(5)

# execute_local_command(lights_on)


execute_local_command(toggle_switch)

#Execute a command with remote connect
def execute_local_command(command):
    command = resolved_external_url + command_base + command
    return print(requests.get(command,auth =basic))




