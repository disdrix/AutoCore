# Review B (skeptical / adversarial): `aa_00833d50` CWndVehicle_DerivedTeardown_EDI

| Field | Value |
|---|---|
| **Stable ID** | `aa_00833d50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (WQ9K-E) |
| **Counterpart** | `reviews/A_aa_00833d50_CWndVehicle_DerivedTeardown_EDI.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is the complete object destructor | **Falsified** — no vtbl install, no base `FUN_0078ca80`, no SEH complete plate |
| 2 | This is the scalar-deleting destructor | **Falsified** — no flags arg, no `operator_delete(this)` |
| 3 | Standard ECX thiscall | **Falsified** — entry uses **EDI**; `MOV ESI,[EDI+0x2A8]` |
| 4 | cdecl / stack this | **Falsified** — no stack this formal |
| 5 | Frees CWndVehicle heap | **Falsified** — bare RET; free is scalar peer only |
| 6 | Nested notify runs only once in complete path | **Falsified as uniqueness** — complete already notifies, helper re-notifies (double sealed) |
| 7 | Same unit as CWndWaypointIcon teardown | **Falsified** — different VA/offsets/callers |
| 8 | Tree/map erase helper (OWN pair co-location) | **Falsified** — pure UI member teardown; no isnil/color |
| 9 | Vehicle_SetWheelset always runs | **Narrowed** — only when host@+0x508 non-null **and** child@+0x258 non-null |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Role = derived teardown (not complete/scalar) | **High** | double-free / miss free / wrong chain |
| EDI=this ABI | **High** | broken port if rewritten as ECX without EDI |
| Offsets +0x2A8/+0x508/+0x50C | **High** | wrong member teardown |
| Host CWndVehicle via complete chain | **High** | naming residual only if wrong |
| Nested product type | **Open** | layout residual |
| Runtime | **Open** | matrix policy |

---

## 3. Cross-check against raw + bytes

```
// FUN_00833d50:
// EDI = this
mov  esi, [edi+2A8h]
mov  dword ptr [edi+50Ch], 0
test esi, esi
jz   skip_nested
; flag +48, copy +40→+44, FUN_0076c4d0, binder vcalls
skip_nested:
mov  eax, [edi+508h]
test eax, eax
jz   done
; optional child@+258 scalar-delete + Vehicle_SetWheelset(0)
; scalar-delete host; [edi+508h]=0
done:
add  esp, 8
ret
```

Live decompile 2026-08-05 ≡ raw 2026-07-23 CF. Entry/exit hex seals EDI ABI and bare RET.  
Complete dual WQ9J-B already documents EDI helper ABI and double-notify.

---

## 4. Surviving contract for AutoCore

```
// Port helper with EDI=this (or rewrite all call sites to pass this):
void CWndVehicle_DerivedTeardown(CWndVehicle* self) {
  self->slot_50C = 0;
  // if nested@+0x2A8: notify plate (may re-notify after complete)
  // if host@+0x508: scalar-delete child@+0x258?, SetWheelset(0), scalar-delete host, null
}
// Do NOT operator_delete(self); do NOT call base here.
// Complete peer owns vtbl install + base FUN_0078ca80.
```

---

## 5. Open questions

1. Nested `@+0x2A8` product class English.  
2. Exact type of vehicle host `@+0x508`.  
3. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
