# Raw capture: FUN_005c6ad0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c6ad0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005c6ad0` |
| **Canonical name** | `FUN_005c6ad0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_005c6ad0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char cVar3;
  
  iVar2 = param_2;
  if (*(int *)(param_2 + 0x10) != 0) {
    iVar1 = *(int *)(param_1 + 0x54);
    if ((iVar1 < 1) || (6 < iVar1)) {
      if (6 < iVar1) {
        *(undefined4 *)(param_1 + 0x54) = 0;
      }
      if (*(int *)(DAT_00d1f050 + 0x6c) != 0) {
        FUN_00971820(param_2);
      }
    }
    param_2 = CONCAT31(param_2._1_3_,1);
    cVar3 = FUN_004ed310(iVar2,&param_2,param_1 + 0x5c);
    if (cVar3 == '\0') {
      *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
      return 3;
    }
  }
  *(undefined4 *)(param_1 + 0x54) = 0;
  return 0;
}
```

---

## W36-F re-verify append (2026-07-29)

**Tools:** Ghidra `batch_decompile` / `analyze_function_complete` + `read_memory` + xrefs + caller decompile `FUN_005c72f0`. **No** `disassemble_bytes`. **No** Launcher.

### Body (bytes win)

- **Range:** `0x005c6ad0`–`0x005c6b3e` exclusive (**110 B** / `0x6E`).
- **Pad:** `CC` then next function.
- **Epilogue:** both exits **`C2 04 00`** (**RET 0x4**).

### Full body hex (110 B)

```
56578b7c240c837f10008bf176538b465485c07e0583f8077c1e83f8077c07c7465400000000a150f0d1008b486c85c9740657e818ad3a008d4e5c518d5424105257c644241801e8f467f2ff83c40c84c0750e834654015fb8030000005ec204005fc746540000000033c05ec20400
```

### ABI (bytes win)

| Slot | Role | Evidence |
|---|---|---|
| **ECX** | load-node / wait host (`MOV ESI,ECX`) | caller `FUN_005c72f0`: `MOV ECX,EDI` (CLoadNode this) |
| **stack +4** | `GuardedVector* ring` | `MOV EDI,[ESP+0xC]` after 2 pushes; `CMP [EDI+0x10],0` (size) |
| **return EAX** | **0** ready / **3** wait-yield | `XOR EAX,EAX` / `MOV EAX,3` |
| cleanup | **RET 0x4** | both exits |

Host layout used:

| Off | Role |
|---|---|
| `+0x54` | int coop-step counter (budget band **1..6**; reset if **>6**) |
| `+0x5c` | uint cursor for `AssPreloader_ProcessKeyRingStep` |

### Semantics (sealed CF)

1. If `ring->size == 0` (bytes: `CMP [EDI+0x10],0` / `JBE` empty path): `host+0x54 = 0`; return **0**.
2. If counter **not in [1,6]**:
   - If counter **>6**: reset counter to **0**.
   - If `*(DAT_00d1f050+0x6c) != 0` (AssPreloader*): `AssPreloader_ExpandDepsAndEnqueueFromRing(preloader, ring)` — ECX from global, push ring.
3. `progress_flag = 1` (stack local); call cdecl `AssPreloader_ProcessKeyRingStep(ring, &flag, &host->cursor@+0x5c)` (`ADD ESP,0xC`).
4. If step returns **AL==0** (yield): `counter++`; return **3**.
5. Else: `counter = 0`; return **0**.

Decompiler `CONCAT31(param_2…,1)` is a **stack-slot reuse artifact** — ring stays in EDI; flag is a separate stack byte set to 1.

### Callers (5 fns / 6 xrefs)

| Caller | Site notes |
|---|---|
| `FUN_005c72f0` (`CLoadNode::_initPreload`) | ring @ clonebase path **+0x174** |
| `FUN_005c7400` | anim-stage wait |
| `FUN_005c76f0` (`CLoadNode__initPhysics`) | ring @ **+0x14c** |
| `FUN_005c78a0` | full-stage wait |
| `FUN_005c79f0` | further stage wait |

### Name

**`CLoadNode_WaitAssPreloadKeyRing_Inferred`** (Inferred structural from CLoadNode stage parents + sealed AssPreloader callees). Reject scaffold `Named_CalleeOf_*` plate.

### Live decompile

2026-07-29 live ≡ raw 2026-07-23 CF. **Bytes win** on ECX=load-host, stack=ring, RET 4, EAX 0/3, ExpandDeps this=AssPreloader.
