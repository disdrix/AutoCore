# Review A (reconstruction fidelity): `aa_005cc460` Object_IsLevelLessThan6

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cc460` |
| **VA** | `0x005cc460`–`0x005cc488` (40 B) |
| **Canonical name** | `Object_IsLevelLessThan6` (structural; product/PDB open) |
| **Ghidra name** | `FUN_005cc460` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W23-R) |
| **Counterpart** | `reviews/B_aa_005cc460_Object_IsLevelLessThan6.md` |
| **System** | `npc-ai` / vehicle pursue gate |
| **Verdict** | **accept** on CF / ABI / GetLevel slot / threshold 6; product symbol **open** |
| **Dual status** | **Present (first full dual)** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + `get_function_by_address`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Null-safe predicate: if object non-null, call **GetLevel** (vtbl+`0x27c`) on MI-adjusted this and return whether **level &lt; 6**. Sole named caller is vehicle pursue’s low-level branch.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record | `docs/reconstruction/functions/aa_005cc460_FUN_005cc460.md` |
| Named record | `docs/reconstruction/functions/aa_005cc460_Object_IsLevelLessThan6.md` |
| Raw | `docs/reconstruction/raw/aa_005cc460_FUN_005cc460.md` (+ W23-R live seal) |
| Annotated | `docs/reconstruction/raw/aa_005cc460_FUN_005cc460.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_IsLevelLessThan6.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005cc460.cpp` |
| Live decompile | Ghidra `decompile_function` `0x005cc460` |
| Live body | `read_memory` 40 B @ entry; `get_function_by_address` body end `005cc488` |
| Callers | `CVOGHBAICreatureBase_DoVehiclePursue` only |

**Not performed:** Launcher, runtime golden, bit-exact image diff.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body **40 B** / end `005cc488` | **Confirmed** | `get_function_by_address` |
| ABI **stdcall** `ret 4` | **Confirmed** | both exit paths `C2 04 00` |
| Null → 0 | **Confirmed** | `test eax,eax; jz` |
| MI this-adjust + vtbl+`0x27c` | **Confirmed** | bytes `lea ecx,[edx+eax+4]` / `call [eax+0x27c]` |
| Compare `level < 6` | **Confirmed** | `cmp eax,6; jge` |
| GetLevel name for slot | **High** | multi-dual project convention |
| Product / PDB name | **Open** | structural |
| Clean ≡ raw ≡ live CF | **Confirmed** | identity |
| Bit-for-bit / runtime | **Open** | deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Load stack arg | Yes |
| Null test | Yes |
| MI this-adjust | Yes |
| call [vtbl+0x27c] | Yes |
| cmp / jge false | Yes |
| mov al,1 / ret 4 | Yes |
| xor al,al / ret 4 | Yes |
| No side effects beyond vcall | Yes |

### Recovered CF

```c
uint8_t Object_IsLevelLessThan6(void *obj)
{
    if (!obj) return 0;
    void *inner = (char*)obj + *(*(int**)((char*)obj+4)+1) /*adj*/ + 4;
    int level = (*(int(__thiscall**)(void*))(*(int*)inner + 0x27c))(inner);
    return level < 6;
}
```

---

## 5. Assembly contract (from `read_memory`)

Hex (40 B through second `ret 4`):
`8b44240485c0741c8b48048b51048d4c02048b01ff907c02000083f8067d05b001c2040032c0c20400`

---

## 6. Callers (OWN context)

| Caller | VA | Role |
|---|---|---|
| `CVOGHBAICreatureBase_DoVehiclePursue` | `0x005cfb60` | if true, low-level pursue path (prior plate wrongly called this “heading”) |

---

## 7. Gaps

1. Retail symbol.
2. Design reason for threshold **6**.
3. Runtime / bit-exact.

**Verdict:** **accept** on sealed CF, stdcall ABI, GetLevel dispatch, threshold 6.