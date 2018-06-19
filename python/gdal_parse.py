import h5py
import pandas as pd

class HDF5():

	def __init__(self):
		pass

	def hdf5_reader(self):

		file_path = './CSKS2_SCS_B_PP_06_CO_RA_SF_20110906053953_20110906053959.h5'
		file = h5py.File(file_path, 'r')

		pd.read_hdf(file_path, key)




if __name__ == '__main__':
	HDF5().hdf5_reader()
