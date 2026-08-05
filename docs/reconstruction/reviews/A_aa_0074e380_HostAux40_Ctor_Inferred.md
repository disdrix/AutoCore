# Review A (reconstruction fidelity): `aa_0074e380` HostAux40_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074e380` |
| **VA** | `0x0074e380`–`0x0074e3d6` exclusive (**86 B** / `0x56`) |
| **Canonical name** | `HostAux40_Ctor_Inferred` |
| **Ghidra name** | `FUN_0074e380` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-R) |
| **Counterpart** | `reviews/B_aa_0074e380_HostAux40_Ctor_Inferred.md` |
| **System** | client / host-base aux (+4 slot via PoolHost 0x40) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `get_function_by_address` + `get_function_xrefs` + `get_function_callees` + `read_memory` (body + `g_flOne`). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Placement ctor for the **0x40-byte** host aux element consumed by `PoolHost_Acquire0x40_Inferred` → stored at `host+4` when `(flags & 1)` in `HostBase_EnsureAuxPtrs_Inferred`:

1. SEH frame `LAB_009ad9f3`.
2. `*self = g_flOne` (`1.0f` @ `0x00a0f2a0`).
3. Zero **`+0x08` / `+0x0c` / `+0x10`** (dword). **`+0x04` intentionally unwritten.**
4. `NestedHash_Ctor_Sentinel0xC_Inferred(self+0x14)` (W34-F; span 0x28).
5. Zero **`+0x3c`**.
6. Return **self** (`RET 4`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W35-R) | `docs/reconstruction/raw/aa_0074e380_FUN_0074e380.md` |
| Annotated | `docs/reconstruction/raw/aa_0074e380_FUN_0074e380.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/HostAux40_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0074e380.cpp` |
| Function records | `functions/aa_0074e380_FUN_0074e380.md`, `functions/aa_0074e380_HostAux40_Ctor_Inferred.md` |
| Related | W33-R `PoolHost_Acquire0x40_Inferred`; W32-Q `HostBase_EnsureAuxPtrs_Inferred`; W34-F `NestedHash_Ctor_Sentinel0xC_Inferred`; peer W33-S `HostAux14_Ctor_Inferred` |
| Live | decompile ≡ raw 2026-07-23; body hex seals stack-self / `movss` / nested call / `C2 04 00`; sole xref `FUN_00986070` @ `0x009860f0` |

---

## 3. Signature (sealed)

```c
// stack self*; RET 4; returns self in EAX (MSVC placement ctor). Not ECX-thiscall.
void *HostAux40_Ctor_Inferred(void *self);
```

| Formal | Source | Conf |
|---|---|---|
| self | stack `[esp+…→0x14]` after prolog (`8B 74 24 14`) | **High** |
| return | self (EAX) | **High** |
| cleanup | `RET 4` (`C2 04 00`) | **High** |

---

## 4. Layout (0x40)

| Offset | Write | Notes |
|---|---|---|
| `+0x00` | `1.0f` | `movss` from `g_flOne` (`0000803f`) |
| `+0x04` | **none** | same leave-gap pattern as HostAux14 `+4` |
| `+0x08` | 0 | |
| `+0x0c` | 0 | |
| `+0x10` | 0 | |
| `+0x14`…`+0x3b` | NestedHash 0xC | `FUN_0043fdf0` / W34-F |
| `+0x3c` | 0 | tail dword |

Alloc size sealed by sole caller: `operator_new(0x40)`.

---

## 5. Control flow (clean ≡ raw ≡ live)

```
SEH LAB_009ad9f3
self[0] = 1.0f
self[+8/+c/+10] = 0
NestedHash_Ctor_Sentinel0xC(self+0x14)
self[+0x3c] = 0
return self; RET 4
```

| Stage | Match | Conf |
|---|---|---|
| Body 86 B / RET 4 | **Yes** | **High** |
| Nested at +0x14 (W34-F sole host embed path) | **Yes** | **High** |
| Sole pool-acquire caller | **Yes** | **High** |
| Size 0x40 | **Yes** | **High** |

Body hex (exclusive end `0x0074e3d6`, pad `CC`):

```
64a100000000f30f1005a0f2a0006aff68f3d99a005064892500000000568b7424145733ff
f30f1106897e08897e0c897e108d461450897c2414e8311acfff8b4c2408897e3c5f8bc6
64890d000000005e83c40cc20400
```

---

## 6. Gaps

- Product / MSVC demangle for the 0x40 aux class.
- Meaning of float head `+0` and unwritten `+4`.
- NestedHash product English (open under W34-F).
- Runtime / bit-exact / differential.

---

## 7. Verdict

Fidelity pass seals placement-ctor role, ABI (`RET 4` / stack self), 0x40 layout, NestedHash embed, and sole pool/HostBase wiring. Residual product English → **accept-with-gaps**.
