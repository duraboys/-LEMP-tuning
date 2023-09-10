#cat /proc/cpuinfo | grep processor | wc -l
#nproc
# 12
pm.max_children = 24
pm.start_servers = 3
pm.min_spare_servers = 3
pm.max_spare_servers = 4
pm.max_requests = 10000

# pm.max_children: CPU 코어 수의 2배 이상을 설정하여 동시 접속량을 처리할 수 있도록 합니다.
# pm.start_servers: 서비스 시작 시 요청 처리를 지연시키지 않기 위해 pm.max_children의 20% 정도의 값을 설정합니다.
# pm.min_spare_servers: CPU나 메모리 사용량이 낮을 때 프로세스를 종료하여 시스템 성능을 향상시킬 수 있습니다.
# pm.max_spare_servers: CPU나 메모리 사용량이 높을 때 프로세스를 추가하여 성능을 향상시킬 수 있습니다.
# pm.max_requests: 프로세스가 메모리 누수를 일으키지 않도록 제한하는 값입니다.

예를 들어, CPU 코어 수가 24개이고, 하루에 이용자가 10만 명인 경우 다음과 같은 설정값을 사용할 수 있습니다.

pm.max_children: 48
pm.start_servers: 6
pm.min_spare_servers: 6
pm.max_spare_servers: 8
pm.max_requests: 10000


pm.max_children: 이 값이 너무 높으면 시스템 리소스가 과부하될 수 있고, 너무 낮으면 동시 접속을 제대로 처리하지 못할 수 있습니다. CPU 코어 수의 2배로 설정하는 것은 일반적인 추천 사항일 뿐입니다.
pm.start_servers: 이 값은 시작 시점에서 생성되는 초기 프로세스 수입니다. 너무 낮으면 서비스 시작 후에 대량의 접속이 올 때 지연이 발생할 수 있습니다. 너무 높으면 불필요한 리소스가 사용될 수 있습니다.
pm.min_spare_servers: 이 값은 유휴 프로세스의 최소 수를 설정합니다. 너무 낮게 설정하면 새로운 접속에 대응하기 위해 프로세스를 새로 생성해야 하므로 지연이 발생할 수 있습니다.
pm.max_spare_servers: 이 값은 유휴 프로세스의 최대 수를 설정합니다. 이 값이 너무 높으면 불필요한 리소스가 사용될 수 있습니다.
pm.max_requests: 이 값은 하나의 자식 프로세스가 처리할 요청의 최대 수입니다. 너무 낮으면 프로세스가 자주 재시작되어 성능에 영향을 미칠 수 있고, 너무 높으면 메모리 누수 등의 문제가 발생할 수 있습니다.

pm.max_children = 50
pm.start_servers = 20
pm.min_spare_servers = 20
pm.max_spare_servers = 35
pm.max_requests = 5000