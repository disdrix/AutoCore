# Review A (reconstruction fidelity): `aa_008718a0` UiHost_ClearTrackedPairAndRefresh_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008718a0` |
| **VA** | `0x008718a0` |
| **Canonical name** | `UiHost_ClearTrackedPairAndRefresh_Inferred` |
| **Ghidra name** | `FUN_008718a0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_008718a0_UiHost_ClearTrackedPairAndRefresh_Inferred.md` |
| **System** | client UI / vehicle-garage host residual |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Tiny **lookup → clear flag → refresh** helper (thiscall `ESI` + two stack dwords).

```c
// bytes seal thiscall + stdcall ret 8
void __thiscall UiHost_ClearTrackedPairAndRefresh(UiHost* this, int keyA, int keyB) {
  int* node = FUN_00871690(this, keyA, keyB);  // walk locked list this+0x628
  if (node != NULL && *node != 0) {
    *node = 0;
    FUN_00871150(node);  // refresh related widgets from node fields
  }
}
```

### Lookup (`FUN_00871690`)

- Locks/list iterates `this+0x628` via `FUN_004294f0` / `FUN_004113b0`.
- Match node where `node+8 == keyA` and `node+0xc == keyB`.
- Leaves CS `this+0x62c` if entered (`this+0x650`).

### Refresh (`FUN_00871150`)

If host visible (`vtbl+0x3d8`), uses node fields (`[2]`,`[3]`, ushorts) to refresh a bank of widgets at host indices `0x17a..0x180` (`vtbl+0x45c/460/464/34c` string/id binding) — inventory/vehicle sheet style labels.

Caller: `FUN_009440e0` (client residual / VOGClient path).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_008718a0_*`, `reconstructed-exact/FUN_008718a0.cpp` |
| Function record | `functions/aa_008718a0_FUN_008718a0.md` |
| Fresh decompile | Ghidra `batch_decompile` @ `0x008718a0` (2026-07-29) |
| Bytes | `read_memory` 48 B — push args, `mov ecx,esi`, call `00871690`, test, zero `*node`, call `00871150`, `ret 8` |
| Callees decompiled | `FUN_00871690`, `FUN_00871150` |

### Bytes (full)

```
008718a0  8B442408          mov  eax, [esp+8]   ; keyB
008718a4  8B4C2404          mov  ecx, [esp+4]   ; keyA
008718a8  50                push eax
008718a9  51                push ecx
008718aa  8BCE              mov  ecx, esi       ; this
008718ac  E8DFFDFFFF        call FUN_00871690
008718b1  85C0              test eax, eax
008718b3  7413              jz   ret
008718b5  833800            cmp  dword [eax], 0
008718b8  740E              jz   ret
008718ba  C70000000000      mov  dword [eax], 0
008718c0  50                push eax
008718c1  8BC6              mov  eax, esi       ; this for 00871150 (in_EAX)
008718c3  E888F8FFFF        call FUN_00871150
008718c8  C20800            ret  8
```

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| thiscall ESI + 2 stack keys, ret 8 | **Confirmed** | bytes |
| Lookup by (keyA,keyB) on list +0x628 | **Confirmed** | `00871690` |
| Clear `*node` only if non-zero then refresh | **Confirmed** | |
| Refresh touches multi-widget bank | **High** | `00871150` body |
| Keys are TFID pair / slot ids | **Tentative** | match fields +8/+0xc |
| Product host class name | **Open** | |
| clean ≡ raw ≡ live | **Confirmed** | 3-call skeleton |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Lookup | Yes |
| Null / already-zero early out | Yes |
| Store 0 + refresh | Yes |

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `FUN_009440e0` | client residual |
| Callee | `FUN_00871690` | pair lookup |
| Callee | `FUN_00871150` | UI refresh from node |

---

## 6. Gaps / open

1. Dual caller `009440e0` for when keys are cleared.
2. Node struct layout / ownership of `*node` flag meaning.
3. Product name of host class around `+0x628` list.
4. Runtime deferred.

**Verdict:** **accept-with-gaps** — clear-and-refresh CF sealed; key semantics Tentative.
