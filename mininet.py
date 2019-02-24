{
    "application": {
        "dpctl": "",
        "ipBase": "10.0.0.0/8",
        "netflow": {
            "nflowAddId": "0",
            "nflowTarget": "",
            "nflowTimeout": "600"
        },
        "openFlowVersions": {
            "ovsOf10": "1",
            "ovsOf11": "1",
            "ovsOf12": "1",
            "ovsOf13": "1"
        },
        "sflow": {
            "sflowHeader": "128",
            "sflowPolling": "30",
            "sflowSampling": "400",
            "sflowTarget": ""
        },
        "startCLI": "1",
        "switchType": "ovs",
        "terminalType": "xterm"
    },
    "controllers": [
        {
            "opts": {
                "controllerProtocol": "tcp",
                "controllerType": "remote",
                "hostname": "c0",
                "remoteIP": "127.0.0.1",
                "remotePort": 6633
            },
            "x": "399.0",
            "y": "104.0"
        }
    ],
    "hosts": [
        {
            "number": "2",
            "opts": {
                "hostname": "h2",
                "ip": "10.0.0.2",
                "nodeNum": 2,
                "sched": "host"
            },
            "x": "453.0",
            "y": "407.0"
        },
        {
            "number": "1",
            "opts": {
                "hostname": "h1",
                "ip": "10.0.0.1",
                "nodeNum": 1,
                "sched": "host"
            },
            "x": "200.0",
            "y": "407.0"
        },
        {
            "number": "3",
            "opts": {
                "hostname": "h3",
                "ip": "10.0.0.3",
                "nodeNum": 3,
                "sched": "host"
            },
            "x": "616.0",
            "y": "410.0"
        }
    ],
    "links": [
        {
            "dest": "h1",
            "opts": {},
            "src": "s1"
        },
        {
            "dest": "h2",
            "opts": {},
            "src": "s2"
        },
        {
            "dest": "h3",
            "opts": {},
            "src": "s2"
        }
    ],
    "switches": [
        {
            "number": "1",
            "opts": {
                "controllers": [
                    "c0"
                ],
                "dpid": "0000000000000001",
                "hostname": "s1",
                "netflow": "0",
                "nodeNum": 1,
                "sflow": "0",
                "switchIP": "",
                "switchType": "ovs"
            },
            "x": "279.0",
            "y": "262.0"
        },
        {
            "number": "2",
            "opts": {
                "controllers": [
                    "c0"
                ],
                "dpid": "0000000000000002",
                "hostname": "s2",
                "netflow": "0",
                "nodeNum": 2,
                "sflow": "0",
                "switchIP": "",
                "switchType": "ovs"
            },
            "x": "515.0",
            "y": "260.0"
        }
    ],
    "version": "2"
}