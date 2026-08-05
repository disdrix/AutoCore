# Review B (skeptical / adversarial): `aa_005b44d0` Obj_009d95b4_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b44d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W30-N) |
| **Counterpart** | `reviews/A_aa_005b44d0_Obj_009d95b4_ScalarDeletingDtor.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the complete-object dtor body | **Falsified** — no vtbl install, no list free; only calls `FUN_005b3b20` then optional free |
| 2 | This is a vector deleting dtor | **Falsified** — no array count / no `operator_delete[]`; single flags bit0 only |
| 3 | cdecl / stack this | **Falsified** — `8B F1`; vtbl thiscall dispatch |
| 4 | Always frees heap | **Falsified** — `test flags,1` / `je` skips delete |
| 5 | Never frees heap | **Falsified** — bit0 path pushes this and calls `operator_delete` |
| 6 | Ghidra noreturn truncates | **Falsified** — full 30 B reaches `MOV EAX,ESI; POP ESI; RET 4` |
| 7 | Same VA as body dtor | **Falsified** — body is `0x005b3b20` |
| 8 | Not vtbl[0] | **Falsified** — dword @ `0x009d95b4` = `0x005b44d0` |
| 9 | Product class known from rdata | **Falsified** — adjacency is `"vs.1.1…"` shader text |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Scalar-deleting vs body | **High** | Double-free / miss free / wrong stack cleanup |
| flags bit0 gate | **High** | Leak or free non-heap this |
| RET 4 | **High** | Stack corruption on virtual call |
| Product English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + vtbl

```
// FUN_005b44d0 (vtbl[0] of PTR_FUN_009d95b4):
push esi
mov  esi, ecx
call FUN_005b3b20          ; body: vtbl + destroy list @ +0x10
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

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Full-body hex seals all branches. Body twin W28-N already sealed list-at-+0x10 + final vtbl.

---

## 4. Surviving contract for AutoCore

```
// Port scalar deleting only (not body):
void* Obj_009d95b4_ScalarDeletingDtor(void* self, uint8_t flags) {
  Obj_BodyDtor_SetVtbl_DestroyStdListAt10(self);  // FUN_005b3b20 — separate unit
  if (flags & 1) operator_delete(self);
  return self;
}
// vtbl[0] entry; ret 4
// Do not inline body dtor into this VA's port.
// Do not invent product class name from shader-adjacent rdata.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/vtbl/false-noreturn. Residual product English is naming-only → **accept**.
