# Review B (skeptical / adversarial): `aa_00834520` CWndVehicle_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00834520` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9J-B) |
| **Counterpart** | `reviews/A_aa_00834520_CWndVehicle_CompleteDtor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is only a scalar-deleting dtor | **Falsified** — no flags arg, no `operator_delete(this)`, installs vtbl and runs member teardown |
| 2 | This is a vector-deleting dtor | **Falsified** — no array count / no `operator_delete[]` |
| 3 | cdecl / stack this | **Falsified** — entry `MOV EDI,ECX` (`8B F9`) |
| 4 | Frees host heap | **Falsified** — bare `RET`; free is scalar peer only |
| 5 | Skips base / no base chain | **Falsified** — `MOV ECX,EDI; CALL FUN_0078ca80` |
| 6 | `FUN_00833d50` is standard thiscall ECX | **Narrowed** — helper uses **EDI=this** (`MOV ESI,[EDI+0x2A8]`); ECX not required at call site |
| 7 | Nested path runs once only | **Falsified as uniqueness claim** — same nested notify also appears inside `FUN_00833d50` when non-null (duplicate sealed) |
| 8 | Not CWndVehicle / wrong vtbl | **Falsified** — installs `00a6fbcc`; RTTI `.?AVCWndVehicle@@`; sole caller is CWndVehicle scalar |
| 9 | Same unit as CWndWaypointIcon complete | **Falsified** — different VA, vtbl, nested offsets, base chain |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Complete vs scalar/vector | **High** | Double-free / miss free / wrong ABI |
| Vtbl + RTTI product name | **High** | Naming only residual closed |
| Nested `+0x2A8` gate | **High** | Miss UI unlink |
| EDI helper ABI | **High** | Broken port if rewritten as ECX thiscall without EDI |
| Nested product type | **Open** | Layout residual only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + vtbl

```
// FUN_00834520 (CWndVehicle complete):
// SEH; EDI = ECX
mov  dword ptr [EDI], 00a6fbcch
mov  ESI, [EDI+2A8h]
test ESI, ESI
jz   skip_nested
; flag/copy/RDTSC/vcalls on nested
skip_nested:
call FUN_00833d50          ; EDI=this
mov  ECX, EDI
call FUN_0078ca80          ; base
; SEH restore; ret
```

Live decompile 2026-08-05 ≡ raw 2026-07-23 CF. Full-body hex seals all branches.  
Scalar peer WQ9I-F pattern: complete then flags&1 delete — consistent.

---

## 4. Surviving contract for AutoCore

```
// Port complete dtor only (not scalar):
void CWndVehicle_CompleteDtor(void* self) {
  *(void**)self = &PTR_FUN_00a6fbcc;
  // if nested@+0x2A8: notify/mark + dual vcall
  // FUN_00833d50 with this in EDI (or rewrite helper to thiscall)
  // FUN_0078ca80(self) base
}
// Do NOT operator_delete(self) here.
// Scalar peer: CWndVehicle_ScalarDeletingDtor @ 0x004160d0
```

---

## 5. Verdict

**accept-with-gaps** — adversarial probes on role/ABI/vtbl/RTTI falsified; nested/helper product English remains open. Terminal **false**.
