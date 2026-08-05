# Function record: HostPtrTable12_Bootstrap_EDI_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073c810` |
| **Canonical name** | `HostPtrTable12_Bootstrap_EDI_Inferred` |
| **Address** | `0x0073c810` |
| **Body** | `0x0073c810`–`0x0073cb6d` (**862 B** / `0x35E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | host pointer-table bootstrap |
| **Completion status** | **Dual A/B complete** (2026-07-29 W35-E) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Ghidra name** | `FUN_0073c810` |

## Purpose

Fill a **12-slot** host pointer table (EDI) with freshly constructed subsystem objects (mix of 0xC4 dual-vtbl hosts, smaller composite hosts, NestedHash bags, and a 0x14C tail host). Returns success code **0**. Closes W34-E/G residual that named this unit only as "bootstrap host" caller.

## Signature

```c
uint32_t HostPtrTable12_Bootstrap_EDI_Inferred(void **table /* EDI */);
```

| Slot | Source | Conf |
|---|---|---|
| table | EDI (not stack; not saved) | **High** |
| return | `XOR EAX,EAX` → 0 | **High** |
| cleanup | `ADD ESP,0x10; RET` | **High** |

## Slot map (summary)

| i | size | ctor family |
|--:|-----:|---|
| 0–4,7–8 | 0xC4 | `FUN_00748960` + dual vtbl + init |
| 5 | 0x44 | `FUN_00457720` |
| 6 | 0x34 | inline multi-vtbl |
| 9 | 0x30 | NestedHash0x10 + tail |
| 10 | 0x40 | NestedHashBag0x18 + tail |
| 11 | 0x14C | `FUN_00764030` + `FUN_007647c0(table[8])` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0073c810_FUN_0073c810.md`
- Annotated: `docs/reconstruction/raw/aa_0073c810_FUN_0073c810.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/HostPtrTable12_Bootstrap_EDI_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0073c810.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_0073c810_FUN_0073c810.md`
- Dual A: `docs/reconstruction/reviews/A_aa_0073c810_HostPtrTable12_Bootstrap_EDI_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0073c810_HostPtrTable12_Bootstrap_EDI_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| ABI EDI + 12 slots + return 0 | **High** |
| NestedHash wiring (W34-E/G) | **High** |
| Product class English | Open |
| Callers | Open (0 xrefs) |
