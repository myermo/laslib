# LASLIB

Simple library for read any .las file, including v1.4, which is not supported by the original liblas (https://liblas.org/)
Also, compiling LASLib and all of its tools for using only the reader it's a bit overkill, so here it is my implementation.


# Requirements

A C/C++ compiler (gcc, clang), make and cmake.


# Installation

Execute `cmake -DCMAKE_BUILD_TYPE=Release . && make`

If you want to install the library globally, execute `make install`

# Usage

The library allows to read(write) point clouds from(to) LAS files.

## Reading a point cloud
Reading a point cloud is carried out through the `LASReader` class:

```LASReader reader(path_to_file)```

This reader allows to retrieve the header and the points of the point cloud:

```auto header = reader.getLasHeader()```

```auto pointReader = reader.getPointReader()```

The `header` contains all the necessary _getters_ to retrieve any desired field.

The `pointReader` reads a point every time the `readPoint()` method is called. After the call, the point information can be retrieved using the corresponding _getters_.

## Writing a point cloud
In order to write a LAS file, we need to build the header and the points. The writing is carried out through the `LASWriter` class.

The header is represented by the class `LASHeader`. All fields must be filled according to the desired LAS specification.

To create a `LASWriter` and write the already existing header:

```
LASWriter lw(path_to_file)
lw.writeHeader(header)
```

In order to write the point, you must create a `PointWriter` with the desired LASPoint format:

```auto pointWriter = lw.getPointWriter(LASPointFormat::Format0```)

After that, loop over your LASPoint and write them one by one using `pointWriter.writePoint(lasPoint)`



