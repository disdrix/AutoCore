# Review A (reconstruction fidelity): `aa_00457720` Class_00aa33a4_PlacementCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00457720` |
| **VA** | `0x00457720`–`0x004577aa` (**139 B** / `0x8B`) |
| **Canonical name** | `Class_00aa33a4_PlacementCtor_Inferred` |
| **Ghidra name** | `FUN_00457720` |
| **Review date** | `2026-07-29` (W36-I dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-I) |
| **Counterpart** | `reviews/B_aa_00457720_Class_00aa33a4_PlacementCtor_Inferred.md` |
| **System** | host class placement ctor |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 139 B) + `analyze_function_complete` + xrefs + element-ctor `read_memory` @ `0x00437630` + W35-G RefCountedPtr3Flags dual. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only. No Launcher. No parent ledger.

---

## 1. Purpose

Placement-construct a **0x44-byte** host object:

1. SEH frame `LAB_009bca04`.
2. `*self = &PTR_FUN_00aa33a4`.
3. Vector-construct **2**×8-byte elems at `+0x14` (`00437440`/`00437450`).
4. Vector-construct **2**×8-byte elems at `+0x24` (`00437630`/`00437640`).
5. Vector-construct **2**× RefCountedPtr3Flags at `+0x34` (`0096f530`/`0096f510`).
6. Return `self`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W36-I append + full hex) | `docs/reconstruction/raw/aa_00457720_FUN_00457720.md` |
| Annotated | `docs/reconstruction/raw/aa_00457720_FUN_00457720.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Class_00aa33a4_PlacementCtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00457720.cpp` |
| Function records | `functions/aa_00457720_FUN_00457720.md`, `…_Class_00aa33a4_PlacementCtor_Inferred.md` |
| Live | decompile ≡ raw CF; 139 B hex; 1 caller |
| Context | W35-E HostPtrTable12 slot5; W35-G RefCountedPtr3Flags |

---

## 3. Signature (sealed)

```c
// stdcall RET 4; return self — NOT ECX-thiscall
void* Class_00aa33a4_PlacementCtor_Inferred(void* self /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| self | stack → ESI (`8B 74 24 14`) | **High** |
| return self | `8B C6` before epilogue | **High** |
| RET | `C2 04 00` | **High** |
| span 0x44 | sole caller `new(0x44)` + last array ends `+0x44` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| vtbl store `00aa33a4` | **Yes** | **High** |
| vector ctor @ +0x14 / +0x24 / +0x34 | **Yes** (LEA offsets in hex) | **High** |
| elem size 8, count 2 each | **Yes** (`6A 02 6A 08`) | **High** |
| RefCountedPtr3Flags pair | **Yes** (W35-G) | **High** |
| +0x04…+0x13 unwritten | **Yes** | **High** |
| Product English | open | **Low** |

---

## 5. Gaps / open

1. Product/PDB class English for `PTR_FUN_00aa33a4`.
2. Unwritten head dwords (filled by post-init `00731130` — unowned).
3. Full duals of element ctors `00437440` / `00437630` (shape sealed via read_memory; product plates open).
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — ABI/layout/vector-ctor ladder sealed; product English residual.
