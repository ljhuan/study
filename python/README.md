os 、sys 、glob、tarfile、subprocess、shutil、tarfile

sys.path.append(path) #添加路径到系统目录中
os.path.isfile(filename) #是否为文件
os.path.isdir(s) #是否为目录
os.path.join(a, *p) #连接路径,中间插入/连接符
os.path.isabs(s) #是否为绝对路径
os.makedirs(dirname, mode=0777) #创建目录
os.stat(filename) #获取文件信息
os.chdir(path) #更改当前工作目录
glob.glob(path) # 获取指定目录下的所有匹配的文件，?(单个) *(多个) [](指定范围)
shutil.rmtree(path) #递归删除目录
shutil.copytree(src, dst, symlinks=False, ignore=None) #递归拷贝目录,symlinks是
否保持符合链接
shutil.copy2(src, dst) #拷贝数据及属性, 类似'cp ‐p src dst'
t=tarfile.open(filename) #打开安装包
t.extractall() #解压安装文件
t=tarfile.open(xxx.tar.gz, 'w:gz')
t.add(filepath) #打包文件
child = subprocess.Popen(['bash', '‐c', '%s' % cmd], stdout=subprocess.PIPE,
stderr=subprocess.PIPE) #执行子进程, stdout
child.returncode #获取进程返回值
subprocess.call(["ls", "‐l"]) subprocess.call("ls ‐l", shell=True) #执行子进
程，并等待其完成
