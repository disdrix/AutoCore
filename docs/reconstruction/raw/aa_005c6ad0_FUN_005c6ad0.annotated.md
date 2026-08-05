# Annotated low-level: CLoadNode_WaitAssPreloadKeyRing_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_005c6ad0` |
| VA | `0x005c6ad0`–`0x005c6b3e` exclusive (**110 B**) |
| Ghidra | `FUN_005c6ad0` |
| Canonical | `CLoadNode_WaitAssPreloadKeyRing_Inferred` |
| System | CLoadNode stage coop-wait + AssPreloader key ring |
| Date | 2026-07-29 (W36-F) |

## Machine-level notes

- **ABI:** `__thiscall`; **ECX = CLoadNode / wait host**; stack **`GuardedVector* ring`**; **`RET 0x4`**; **EAX = 0 ready / 3 wait**.
- Entry: `PUSH ESI/EDI`; `MOV EDI,[ESP+0xC]` (ring); `MOV ESI,ECX` (host).
- Empty ring: `CMP [EDI+0x10],0` / `JBE` → zero counter, return 0.
- Counter at **`host+0x54`**: if outside **[1,6]**, optionally reset when **>6**, then ExpandDeps if AssPreloader live.
- Cursor at **`host+0x5c`** passed to sealed `AssPreloader_ProcessKeyRingStep`.
- Decompiler `CONCAT31(param_2…,1)` is stack reuse for **progress_flag=1** — ring remains EDI.

## Control flow (annotated)

```
if ring.size == 0:
  host.counter = 0; return 0
if counter not in [1..6]:
  if counter > 6: counter = 0
  if AssPreloader* = *(DAT_00d1f050+0x6c):
    ExpandDepsAndEnqueueFromRing(preloader, ring)   // ECX=preloader, stack=ring
flag = 1
if ProcessKeyRingStep(ring, &flag, &host.cursor) == 0:  // yield
  host.counter++
  return 3
host.counter = 0
return 0
```

## Callers

CLoadNode stage inits (`_initPreload`, physics, anim, full, …) pass clonebase-owned rings at stage-specific offsets (`+0x174`, `+0x14c`, `+0x138`, `+0x160`, …). Return **3** bubbles as stage “wait”.

## Pseudocode

See raw capture + clean `CLoadNode_WaitAssPreloadKeyRing_Inferred.cpp`.
