# Review B (skeptical / adversarial): `aa_004280d0` CNDUIDialog_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004280d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-140) |
| **Counterpart** | `reviews/A_aa_004280d0_CNDUIDialog_ScalarDeletingDtor.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the complete-object dtor body | **Falsified** — no vtbl install / member frees here; only calls `FUN_00792c20` then optional free |
| 2 | This is a vector deleting dtor | **Falsified** — no array count / no `operator_delete[]`; single flags bit0 only |
| 3 | cdecl / stack this | **Falsified** — `8B F1`; vtbl thiscall dispatch; `RET 4` |
| 4 | Always frees heap | **Falsified** — `test flags,1` / `je` skips delete |
| 5 | Never frees heap | **Falsified** — bit0 path pushes this and calls `operator_delete` |
| 6 | Ghidra noreturn truncates body | **Falsified** — full 30 B reaches `MOV EAX,ESI; POP ESI; RET 4` |
| 7 | Same unit as complete `00792c20` | **Falsified** — complete has no flags arg and does not free host (WQ9K-G) |
| 8 | Not vtbl[0] / wrong product class | **Falsified** — dword @ `00a98f44` = this VA; COL → `.?AVCNDUIDialog@@` |
| 9 | Product name is scaffold / `_Inferred` only | **Falsified** — RTTI type_info string present and demangles to CNDUIDialog |
| 10 | Skills-system exclusive identity | **Falsified as product class** — partition tag is skills-abilities residual, but type is shared UI base; name must stay CNDUIDialog |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Scalar-deleting vs complete body | **High** | Double-free / miss free / wrong stack cleanup |
| flags bit0 gate | **High** | Leak or free non-heap this |
| RET 4 | **High** | Stack corruption on virtual call |
| Product RTTI name | **High** | Naming residual closed |
| Complete dtor internals | **Open** (not owned; dualed WQ9K-G) | Port must call, not inline |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + vtbl

```
// FUN_004280d0 (vtbl[0] of PTR_FUN_00a98f44 / CNDUIDialog):
push esi
mov  esi, ecx
call FUN_00792c20          ; complete body (thiscall)
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
Sibling pattern matches WQ9I-F `CWndVehicle_ScalarDeletingDtor` (identical 30 B layout).  
WQ9K-G B review already identified this VA as the scalar peer of complete `00792c20`.

---

## 4. Surviving contract for AutoCore

```
// Port scalar deleting only (not complete body):
void* CNDUIDialog_ScalarDeletingDtor(void* self, uint8_t flags) {
  CNDUIDialog_CompleteDtor(self);   // FUN_00792c20 — separate unit
  if (flags & 1) operator_delete(self);
  return self;
}
// vtbl[0] of PTR_FUN_00a98f44; ret 4
// Do not inline complete body into this VA's port.
// Do not treat this as skills-only type — it is CNDUIDialog base UI.
```

---

## 5. Verdict

**accept** — adversarial probes falsified; sealed contract holds. Terminal **false**.
