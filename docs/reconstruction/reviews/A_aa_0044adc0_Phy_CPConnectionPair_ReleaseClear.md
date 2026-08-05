# Review A (reconstruction fidelity): `aa_0044adc0` Phy_CPConnectionPair_ReleaseClear

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044adc0` |
| **VA** | `0x0044adc0`–`0x0044ae50` |
| **Canonical name** | `Phy_CPConnectionPair_ReleaseClear` |
| **Ghidra name** | `FUN_0044adc0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W22-S) |
| **Counterpart** | `reviews/B_aa_0044adc0_Phy_CPConnectionPair_ReleaseClear.md` |
| **System** | physics-cpconnection |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory`; sibling `0x0044af00`; 7 callers |
| **Verdict** | **accept** |

---

## 1. Purpose

Tear down a dual CP-connection bind pair: clear owner-outs at `+0`/`+8`, release refcounted smart slots at `+4`/`+0xC` (`refcount--`, `vtbl+8` if zero), then call `FUN_00437150` on both slots. Stdcall `ret 4`. Does not `delete` the pair block.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0044adc0_FUN_0044adc0.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_0044adc0_FUN_0044adc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Phy_CPConnectionPair_ReleaseClear.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0044adc0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0044adc0_FUN_0044adc0.md` |
| Sibling bind | `Phy_CPConnection_AssertConnectionPoint` `0x0044af00` |
| Callee | `FUN_00437150` `0x00437150` |
| Live | decompile ≡ raw; `read_memory` 145 B; rel32 → `0x00437150` ×2 |

---

## 3. Signature (sealed)

```c
void __stdcall Phy_CPConnectionPair_ReleaseClear(CPConnectionPair *pair);
```

| Formal | Source | Conf |
|---|---|---|
| pair | stack arg → ESI | **High** |
| convention | **`ret 4`** | **High** |
| SEH | `fs:[0]` + `LAB_009bcaea` | **High** |

### Layout

| Off | Role |
|---|---|
| +0x00 | owner/raw out 1 — clear |
| +0x04 | smart A — Release protocol |
| +0x08 | owner/raw out 2 — clear first |
| +0x0C | smart B — Release protocol |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
pair[+0x08] = 0
release pair[+0x0C]
pair[+0x00] = 0
release pair[+0x04]
FUN_00437150(&pair[+0x0C])
FUN_00437150(&pair[+0x04])
ret 4
```

| Stage | Match | Conf |
|---|---|---|
| Order clear/release | **Yes** | **High** |
| Refcount at obj+4; call vtbl+8 | **Yes** | **High** |
| Callee `0x00437150` ×2 | **Yes** | **High** |
| Pair matches `0x0044af00` bind slots | **Yes** | **High** |
| Product name exact | **Probable** | inferred |

---

## 5. Machine bytes (`read_memory`)

Hex body (145 B through `ret 4`):
```
64a1000000006aff68eaca9b005064892500000000568b74241457c7442410010000008d7e0cc74608000000008b0f85c97411834104ff75058b01ff5008c70700000000c706000000008b4e0483c60485c97411834104ff75058b11ff5208c7060000000057c644241400e820c3feff56c7442414ffffffffe812c3feff8b4c24085f64890d000000005e83c40cc20400
```

Callee targets sealed to `FUN_00437150`. Decompile ≡ bytes for CF; stdcall residual fixed from `C2 04 00`.

---

## 6. Gaps

1. Exact C++ type spelling of pair / smart object.  
2. Why `FUN_00437150` after already-null slots (template residue).  
3. Runtime / bit-exact.

---

## Verdict

**accept** — dual-slot Release/clear kernel and stdcall ABI sealed; product English Probable via phyCPConnection sibling.
