# Review B (skeptical / adversarial): `aa_004130d0` CVOGDialog_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004130d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R12-010) |
| **Counterpart** | `reviews/A_aa_004130d0_CVOGDialog_ScalarDeletingDtor.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the complete-object dtor body | **Falsified** — no vtbl install / member frees here; only calls `FUN_0087b7d0` then optional free |
| 2 | This is a vector deleting dtor | **Falsified** — no array count / no `operator_delete[]`; single flags bit0 only |
| 3 | cdecl / stack this | **Falsified** — `8B F1`; vtbl thiscall dispatch |
| 4 | Always frees heap | **Falsified** — `test flags,1` / `je` skips delete |
| 5 | Never frees heap | **Falsified** — bit0 path pushes this and calls `operator_delete` |
| 6 | Ghidra noreturn truncates | **Falsified** — full 30 B reaches `MOV EAX,ESI; POP ESI; RET 4` |
| 7 | Same unit as complete dtor `0087b7d0` | **Falsified** — complete installs vtbl + chains `00792c20`; this is wrapper only |
| 8 | Not vtbl[0] / not CVOGDialog | **Falsified** — dword @ `00a58c6c` = this VA; parent RTTI `.?AVCVOGDialog@@` |
| 9 | Product name is scaffold / needs `_Inferred` | **Falsified** — RTTI type_info string present via parent dual + this slot |
| 10 | Mission-state mutator / C2S | **Falsified** — pure delete wrapper; no mission fields |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Scalar-deleting vs complete body | **High** | Double-free / miss free / wrong stack cleanup |
| flags bit0 gate | **High** | Leak or free non-heap this |
| RET 4 | **High** | Stack corruption on virtual call |
| Product RTTI name | **High** | Naming residual closed by parent dual |
| Complete dtor internals | **Open** (not owned) | Port must call, not inline |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + vtbl

```
// FUN_004130d0 (vtbl[0] of PTR_FUN_00a58c6c / CVOGDialog):
push esi
mov  esi, ecx
call FUN_0087b7d0          ; complete body (thiscall)
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
Sibling pattern matches WQ9I-F `CWndVehicle_ScalarDeletingDtor` and mega `CNDUIDialog_ScalarDeletingDtor`.

---

## 4. Surviving contract for AutoCore

```
// Port scalar deleting only (not complete body):
void* CVOGDialog_ScalarDeletingDtor(void* self, uint8_t flags) {
  CVOGDialog_CompleteDtor(self);   // FUN_0087b7d0 — separate unit
  if (flags & 1) operator_delete(self);
  return self;
}
// vtbl[0] of PTR_FUN_00a58c6c; ret 4
// Do not inline complete body into this VA's port.
```

---

## 5. Verdict

**accept** — adversarial probes falsified; sealed contract holds. Terminal **false**.
