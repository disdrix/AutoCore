# Review B (skeptical / adversarial): `aa_004160d0` CWndVehicle_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004160d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9I-F) |
| **Counterpart** | `reviews/A_aa_004160d0_CWndVehicle_ScalarDeletingDtor.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the complete-object dtor body | **Falsified** — no vtbl install / member frees here; only calls `FUN_00834520` then optional free |
| 2 | This is a vector deleting dtor | **Falsified** — no array count / no `operator_delete[]`; single flags bit0 only |
| 3 | cdecl / stack this | **Falsified** — `8B F1`; vtbl thiscall dispatch |
| 4 | Always frees heap | **Falsified** — `test flags,1` / `je` skips delete |
| 5 | Never frees heap | **Falsified** — bit0 path pushes this and calls `operator_delete` |
| 6 | Ghidra noreturn truncates | **Falsified** — full 30 B reaches `MOV EAX,ESI; POP ESI; RET 4` |
| 7 | Same unit as `004160f0` | **Falsified** — different complete dtor, different vtbl/RTTI host |
| 8 | Not vtbl[0] / not CWndVehicle | **Falsified** — dword @ `00a6fbcc` = this VA; COL → `.?AVCWndVehicle@@` |
| 9 | Product name is scaffold only | **Falsified** — RTTI type_info string present |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Scalar-deleting vs complete body | **High** | Double-free / miss free / wrong stack cleanup |
| flags bit0 gate | **High** | Leak or free non-heap this |
| RET 4 | **High** | Stack corruption on virtual call |
| Product RTTI name | **High** | Naming only residual closed |
| Complete dtor internals | **Open** (not owned) | Port must call, not inline |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + vtbl

```
// FUN_004160d0 (vtbl[0] of PTR_FUN_00a6fbcc / CWndVehicle):
push esi
mov  esi, ecx
call FUN_00834520          ; complete body (thiscall)
test byte ptr [esp+8], 1
je   skip
push esi
call operator_delete
add  esp, 4
skip:
mov  eax, esi
pop  esi
ret  4
```

Live decompile 2026-08-05 ≡ raw 2026-07-23 CF. Full-body hex seals all branches.  
Sibling pattern matches W31-E `Class_009c7938_ScalarDeletingDtor`.

---

## 4. Surviving contract for AutoCore

```
// Port scalar deleting only (not complete body):
void* CWndVehicle_ScalarDeletingDtor(void* self, uint8_t flags) {
  CWndVehicle_CompleteDtor(self);   // FUN_00834520 — separate unit
  if (flags & 1) operator_delete(self);
  return self;
}
// vtbl[0] of PTR_FUN_00a6fbcc; ret 4
// Do not inline complete body into this VA's port.
```

---

## 5. Verdict

**accept** — adversarial probes falsified; sealed contract holds. Terminal **false**.
