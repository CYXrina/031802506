#!/usr/bin/env python3

def opening(filename):
	with open(filename, 'r') as f:
		m = f.readlines()
		return m

'''
def write_in(filename, string):
	with open(filename, 'r+') as f:
		f.seek(0, 2)
		f.write(string+'\n')

'''

m = opening('packet_capture')
for i in m:
	if 'length' in i:
		if str(i.split('length ')[-1]).split(':')[0] != '0\n':
			i = i.split('IP ')[1]
			i = i.split(':')[0]+' '+str(i.split('length ')[-1]).split(':')[0]
			print(i)
			# write_in('Request.txt', i)
