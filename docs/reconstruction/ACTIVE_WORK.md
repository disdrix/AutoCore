# Active Work

| Field | Value |
|-------|-------|
| Session | 2026-08-06 **B1000 dual burst LAUNCHED** |
| Status | **in flight** — workflow `b1000-dual-burst` (1000 OWN agents) |
| Partition | `reviews/WAVE_2026-08-06_b1000_burst_partition_map.md` |
| Dual start | **2726** |
| Launched | **1000** attempted via parallel panel (`agent_budget=1000`) |
| Terminal | false |
| Completion policy | dual/`full`/`reviewed` are **byproducts** — not project complete |

## Rules

- OWN agents: one VA each; **no** parent ledger edits  
- Parent merges only after duals land (filesystem A∩B recount)  
- Scaffolds must not raise completion metrics  
- Runtime Confirmed only with Launcher approval  
