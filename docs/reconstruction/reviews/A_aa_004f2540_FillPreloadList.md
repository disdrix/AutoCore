# Review A (reconstruction fidelity): `aa_004f2540` FillPreloadList

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f2540` |
| **VA** | `0x004f2540`–`0x004f26d5` inclusive (**406 B**) |
| **Canonical name** | `FillPreloadList` |
| **Ghidra name** | `FUN_004f2540` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-L) |
| **Counterpart** | `reviews/B_aa_004f2540_FillPreloadList.md` |
| **System** | client-load / preload pipeline |
| **Evidence pass** | Live Ghidra `batch_decompile` + `get_function_by_address` + `read_memory` (body hex) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Fill the load host's primary preload list (`GuardedVector` @ `+0x124`) after collecting transitive dependency keys into `+0x110`. Product profiler plate **`FillPreloadList`**. Optional graphics/anim/phy/snd collectors when manager gate set. Fail if asset name@`+0x188` empty/space.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W32-L append) | `docs/reconstruction/raw/aa_004f2540_FUN_004f2540.md` |
| Annotated | `docs/reconstruction/raw/aa_004f2540_FUN_004f2540.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FillPreloadList.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_004f2540.cpp` |
| Function record | `docs/reconstruction/functions/aa_004f2540_FillPreloadList.md` |
| Consumer | `aa_005c72f0` `CLoadNode__initPreload` |
| Nested dual | `aa_00744360` (this wave); `aa_0043e3d0` PushFront (W31-I) |
| Live | decompile ≡ raw CF; bytes fix ECX for clear/push |

---

## 3. Signature (sealed)

```c
// ECX = load host; bare C3; AL = 0|1
uint8_t __fastcall FillPreloadList(void* self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F1`) | **High** |
| return 0/1 | `32 C0` / `B0 01` paths | **High** |
| cleanup | bare `C3` after `ADD ESP,0x11C` | **High** |

---

## 4. Control flow (bytes authority)

```
SEH + profiler("FillPreloadList")
FUN_0043d650(0) with ECX=self+0x124
if name@+0x188 empty/space → profiler leave; return 0
FUN_004eb1c0(self, &key)                     // name → key
ECX=*(DAT_00d1f050+0x64); FUN_00744360(key, self+0x110)
if *(DAT_00d1f050+0x6c): FUN_004f1ff0(self+0x124)
if *(short*)(*(self+0x3c)+0x3f4)==3:
  name+".spt" → FUN_00989e00 → key_spt; push_key=key_spt
else push_key=key
GuardedVector_PushFront_Thiscall(ECX=self+0x124, push_key)
if gate: Anim(+0x138), Phy(+0x14c), Snd(+0x160)
profiler leave; return 1
```

| Stage | Match | Conf |
|---|---|---|
| Plate string | `read_memory` `0x009cd090` = `FillPreloadList\0` | **High** |
| `.spt` constant | `DAT_009cd088` = `2e737074` | **High** |
| Empty-name fail | decompile ≡ three tests | **High** |
| Dep collect + push | decompile + ECX from bytes | **High** |
| Sole CALL site | xref `005c73c1` | **High** |
| Clear/push this @+0x124 | bytes `LEA EBX,[ESI+0x124]` | **High** |

---

## 5. Gaps

1. Product/PDB load-host class English (beyond plate method).  
2. Nested dual ownership for `FUN_004eb1c0` / `FUN_0043d650` / `FUN_004f1ff0`.  
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — CF/ABI/offsets/plate **sealed**.
