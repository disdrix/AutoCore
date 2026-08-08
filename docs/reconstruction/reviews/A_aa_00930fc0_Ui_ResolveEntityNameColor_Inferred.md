# Review A (reconstruction fidelity): `aa_00930fc0` Ui_ResolveEntityNameColor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00930fc0` |
| **VA** | `0x00930fc0`–`0x009313bf` |
| **Canonical name (Ghidra)** | `FUN_00930fc0` |
| **Proposed name** | `Ui_ResolveEntityNameColor_Inferred` |
| **Review date** | `2026-08-04` (WQ9D-J OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_00930fc0_Ui_ResolveEntityNameColor_Inferred.md` |
| **System** | client UI / entity label color |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Resolve a packed **AARRGGBB** color for drawing an entity **name/label** relative to the local player (`clientCtx+0xe98`). Not a cast manager, not combat damage, not TFID leaf (those are callees).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` / `analyze_function_complete` @ `0x00930fc0` |
| Bytes | `read_memory` prologue + epilogue (`C2 10 00`) |
| Meta | body `00930fc0`–`009313bf` (**1023 B**) |
| Callers | 5: `FUN_00836410`, `FUN_00838e20`, `FUN_00859bc0`, `FUN_009188c0`, `FUN_0091a350` |
| Xrefs | 8 call sites |
| Callees | `Object_GetRootRaceId`, `FUN_00837e80`, `FUN_005749d0` (VehicleCrew_ContainsMember), `FUN_0040b1b0`, `FUN_0040aff0`, `TFID_EqualsObjectId`, `FUN_00930f40`, `FUN_0092d580` |
| Peer duals | `aa_0040aff0`, `aa_00404aa0`, `aa_005749d0`, `aa_0040b1b0` |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_00930fc0` |

**Not performed:** Launcher, runtime, bit-exact, parent ledgers.

---

## 3. Signature

```c
void __thiscall Ui_ResolveEntityNameColor_Inferred(
    void *entity /*ECX*/,
    void *clientCtx,
    uint32_t *outArgb,
    char flagAllowSelfStyle,
    char flagForcePalette);
// ret 16
```

| Item | Evidence |
|---|---|
| Convention | epilogue `C2 10 00`; ECX = entity in analyze variables |
| Out store | `*param_3 = local_18` single exit `code_r0x0093139e` |
| Special ARGB | immediates `0xFFC364EB`, `0xFFEBEBEB`, `0xDFCAFF0B` |
| Scale | `DAT_00aaa6f8` = **255.0f** (`read_memory` `00007f43`) |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null → palette | Yes |
| sub+0x6b4 > 0 → purple | Yes |
| No local → palette | Yes |
| Self / privileged peer → palette | Yes |
| Race gate + crew suppress | Yes |
| Dead → gray | Yes |
| Owner TFID → lime | Yes |
| rel vtbl+0x298 / force flag | Yes |
| Level-band pack A=FF | Yes |
| Single store to *out | Yes |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| UI name-color role | **High** | callers are name sprintf + draw paths |
| ABI ret 16 / ECX entity | **High** | bytes + locals |
| Special ARGB values | **High** | decompile immediates |
| Palette helper modes | **High** CF / **Probable** English | `FUN_00930f40` bytes |
| Product English name | **Tentative** | `_Inferred` |
| `+0x6b4` product meaning | **Open** | “marked” only by CF |
| flagA / flagB product names | **Probable** | role from CF only |

---

## 6. Gaps / open

1. Product/PDB symbol.  
2. Exact English for purple gate field `+0x6b4`.  
3. Full formal type of `clientCtx`.  
4. Level-band host object for `FUN_0092d580` (tables at +0xbe4..).  
5. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — CF/ABI/colors High; product English open.
