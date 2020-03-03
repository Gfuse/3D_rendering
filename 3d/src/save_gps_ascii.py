#!/usr/bin/python
import os
import csv
import numpy
import argparse
from matplotlib import pyplot


def read_estimate(filename):
	data = list(csv.reader(open(filename, 'r'), delimiter=' ', skipinitialspace=True))
	node_time = [(x[1], x[2]) for x in data if x[0] == 'stamp']
	gps_time = [(x[1], x[2]) for x in data if x[0] == 'utm_stamp']
	gps_coord = [(x[1], x[2], x[3]) for x in data if x[0] == 'utm_coord']
	
	if not len(gps_coord):
		return None

	node_time = float(node_time[0][0]) + float(node_time[0][1]) * 1e-9
	gps_time = float(gps_time[0][0]) + float(gps_time[0][1]) * 1e-9
	gps_coord = numpy.float64(gps_coord[0])

	return [node_time, gps_time, gps_coord]

def main():
	parser = argparse.ArgumentParser()
	parser.add_argument('directory')
	args = parser.parse_args()

	directory = args.directory

	if os.path.exists(directory + '/zero_utm'):
		zero_utm = numpy.loadtxt(directory + '/zero_utm')

	with open(directory + '/gps_data', 'w') as f:
		print >> f, '# node_id node_stamp[sec] gps_stamp[sec] utm_x[m] utm_y[m] utm_z[m]'
		for keyframe in sorted(os.listdir(directory)):
			if not os.path.isdir(directory + '/' + keyframe):
				continue
			data = read_estimate(directory + '/' + keyframe + '/data')

			if data is None:
				continue

			data[2] += zero_utm
			
			print '%s %.10f %.10f %.20f %.20f %.20f' % (keyframe, data[0], data[1], data[2][0], data[2][1], data[2][2])
			print >> f, '%s %.10f %.10f %.20f %.20f %.20f' % (keyframe, data[0], data[1], data[2][0], data[2][1], data[2][2])



if __name__ == '__main__':
	main()
