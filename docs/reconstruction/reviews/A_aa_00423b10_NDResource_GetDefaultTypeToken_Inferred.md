# Review A (reconstruction fidelity): `aa_00423b10` NDResource_GetDefaultTypeToken_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00423b10` |
| **VA** | `0x00423b10`–`0x00423b3f` |
| **Canonical name** | `NDResource_GetDefaultTypeToken_Inferred` (structural) |
| **Ghidra name** | `FUN_00423b10` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W18-D) |
| **Counterpart** | `reviews/B_aa_00423b10_NDResource_GetDefaultTypeToken_Inferred.md` |
| **System** | ND resource cache / type token |
| **Verdict** | **accept** |

---

## 1. Purpose

**One-shot factory** for the default ND resource **type token** used by `NDResource_LoadByKey`:

```
type = FUN_00423b10();
piVar3 = NDResourceCache_LookupOrCreate(DAT_00d1f050, key, type, param_3, param_4);
```

CF:

1. If once-flag bit 0 at `0x00d1f738` is clear:
   - Set bit 0.
   - Store vtable `PTR_FUN_00a95ae8` into object dword at `0x00d1f734`.
   - `atexit(LAB_009c3070)`.
2. Return `&DAT_00d1f734` (address of the singleton object).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_00423b10_*`, `FUN_00423b10.cpp`, `NDResource_GetDefaultTypeToken_Inferred.cpp` |
| Function record | `functions/aa_00423b10_NDResource_GetDefaultTypeToken_Inferred.md` |
| Fresh decompile | Ghidra `decompile_function` @ `0x00423b10` ≡ raw |
| Bytes | `read_memory` 128 B — full 0x30-byte body |
| Parent dual | `A_aa_00423ac0_NDResource_LoadByKey.md` |
| atexit thunk | `read_memory` @ `0x009c3070` — `mov eax,&DAT_00d1f734; jmp rel` |

**Not performed:** `disassemble_bytes`, Launcher, full vtable method map.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Once-flag bit 0 at `d1f738` | **Confirmed** | `test`/`or` bytes |
| Vptr store `d1f734 ← a95ae8` | **Confirmed** | `c7 05 … e8 5a a9 00` |
| Return `&d1f734` not vptr value | **Confirmed** | `mov eax, 00d1f734; ret` |
| atexit registration | **Confirmed** | push lab; call; `add esp,4` |
| Role = type token for cache | **High** | sole caller LoadByKey |
| Product class English | **Open** | |
| clean ≡ raw CF | **Yes** | trivial body |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Live decompile ≡ raw | **Yes** |
| Flag / store / atexit / return | **Yes** |
| No stack formals | **Yes** |

### Recovered CF

```c
void* NDResource_GetDefaultTypeToken(void) {
  if ((g_once & 1) == 0) {
    g_once |= 1;
    g_obj.vtbl = &PTR_FUN_00a95ae8;
    atexit(LAB_009c3070);
  }
  return &g_obj;
}
```

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `NDResource_LoadByKey` | sole |
| Callee | `_atexit` | process exit |
| Data | `LAB_009c3070` | destructor thunk |
| Data | `PTR_FUN_00a95ae8` | type vtable |

---

## 6. Gaps / open

1. Product name of type class / vtable methods.
2. Sibling one-shot tokens (nearby `0x00423b40`-class patterns) — out of scope.
3. Runtime — open.

**Verdict:** **accept** — trivial sealed singleton; naming remains inferred.
