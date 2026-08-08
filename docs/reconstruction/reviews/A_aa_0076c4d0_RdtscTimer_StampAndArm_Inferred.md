# Review A (reconstruction fidelity): `aa_0076c4d0` RdtscTimer_StampAndArm_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076c4d0` |
| **VA** | `0x0076c4d0`–`0x0076c4f1` exclusive (**33 B** / `0x21`) |
| **Canonical name** | `RdtscTimer_StampAndArm_Inferred` |
| **Ghidra name** | `FUN_0076c4d0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9L-D) |
| **Counterpart** | `reviews/B_aa_0076c4d0_RdtscTimer_StampAndArm_Inferred.md` |
| **System** | timer subobject / HostBase nested; UI dtor chain leaf |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full 33 B) + callers/xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Leaf: stamp RDTSC into timer `+0x08/+0x0C` and set arm flag `+0x18 = 1`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9L-D append) | `docs/reconstruction/raw/aa_0076c4d0_FUN_0076c4d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0076c4d0_FUN_0076c4d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/RdtscTimer_StampAndArm_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0076c4d0.cpp` |
| Function records | `aa_0076c4d0_FUN_0076c4d0.md`, `aa_0076c4d0_RdtscTimer_StampAndArm_Inferred.md` |
| Live | decompile ≡ raw CF ≡ full-body hex; 90 xrefs; HostBase / CWndVehicle callers |

---

## 3. Signature (sealed)

```c
// ECX = timer*; bare C3; void
void __fastcall RdtscTimer_StampAndArm_Inferred(void *timer);
```

| Formal | Source | Conf |
|---|---|---|
| timer | ECX (`89 41 08` / `C6 41 18 01`) | **High** |
| return | void | **High** |
| cleanup | `83 C4 08 C3` | **High** |
| stack formals | none | **High** |

---

## 4. Control flow (bytes authority)

```
SUB ESP, 8
RDTSC
spill EAX/EDX to [ESP]/[ESP+4]
reload EAX/EDX
[ECX+8]  = EAX
[ECX+0xC] = EDX
[ECX+0x18] = 1
ADD ESP, 8
RET
```

| Stage | Match | Conf |
|---|---|---|
| RDTSC opcode `0F 31` | full hex | **High** |
| Stores `+8` / `+0xC` | `89 41 08` `89 51 0C` | **High** |
| Flag `+0x18=1` | `C6 41 18 01` | **High** |
| Bare RET | `C3` | **High** |
| Decompile ≡ raw 2026-07-23 | identical body | **High** |

---

## 5. Machine bytes (`read_memory`)

```
83 EC 08 0F 31 89 04 24 89 54 24 04 8B 04 24 8B 54 24 04
89 41 08 89 51 0C C6 41 18 01 83 C4 08 C3
```

33 B; no padding inside body; `CC` align after.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | leaf |
| Xrefs | 90 |
| Key callers | `FUN_0076c500`; HostBase ctor `0x007560d0`; CWndVehicle complete `0x00834520` / derived `0x00833d50` |

---

## 7. Gaps

1. Product English / RTTI for timer subobject type.  
2. Product meaning of `+0x18` beyond arm-after-stamp.  
3. Full dual of init twin `FUN_0076c500` (not owned).  
4. Runtime / bit-exact / differential — open.

---

## 8. Verdict

ABI, body size, RDTSC stamp offsets, arm flag, and leaf role sealed. Product demangle open → **accept-with-gaps**.
