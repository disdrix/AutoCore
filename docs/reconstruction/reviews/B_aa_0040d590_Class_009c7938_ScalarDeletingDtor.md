# Review B (skeptical / adversarial): `aa_0040d590` Class_009c7938_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d590` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-E) |
| **Counterpart** | `reviews/A_aa_0040d590_Class_009c7938_ScalarDeletingDtor.md` |
| **Scratch** | `tmp/a_0040d590.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the complete-object dtor body | **Falsified** — no vtbl install, no member frees; only calls `FUN_0040d820` then optional free |
| 2 | This is a vector deleting dtor | **Falsified** — no array count / no `operator_delete[]`; single flags bit0 only |
| 3 | cdecl / stack this | **Falsified** — `8B F1`; vtbl thiscall dispatch |
| 4 | Always frees heap | **Falsified** — `test flags,1` / `je` skips delete |
| 5 | Never frees heap | **Falsified** — bit0 path pushes this and calls `operator_delete` |
| 6 | Ghidra noreturn truncates | **Falsified** — full 29 B reaches `MOV EAX,ESI; POP ESI; RET 4` |
| 7 | Same VA as tree clear | **Falsified** — clear is `0x0040d5b0` (next function after pad) |
| 8 | Not vtbl[0] | **Falsified** — dword @ `0x009c7938` = `0x0040d590` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Scalar-deleting vs complete body | **High** | Double-free / miss free / wrong stack cleanup |
| flags bit0 gate | **High** | Leak or free non-heap this |
| RET 4 | **High** | Stack corruption on virtual call |
| Product English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + vtbl

```
// FUN_0040d590 (vtbl[0] of PTR_FUN_009c7938):
push esi
mov  esi, ecx
call FUN_0040d820          ; complete body
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

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Full-body hex seals all branches.  
Sibling pattern matches W29-F `Class_009c7a1c_ScalarDeletingDtor`.

---

## 4. Surviving contract for AutoCore

```
// Port scalar deleting only (not complete body):
void* Class_009c7938_ScalarDeletingDtor(void* self, uint8_t flags) {
  Class_009c7938_CompleteDtor(self);   // FUN_0040d820 — separate unit
  if (flags & 1) operator_delete(self);
  return self;
}
// vtbl[0] entry; ret 4
// Do not inline complete body or tree clear into this VA's port.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/vtbl/false-noreturn. Residual product English is naming-only → **accept**.
