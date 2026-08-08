# Review B (skeptical / adversarial): `aa_00423e50` CNDUIWindow_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00423e50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-139) |
| **Counterpart** | `reviews/A_aa_00423e50_CNDUIWindow_ScalarDeletingDtor.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the complete-object dtor body | **Falsified** — no vtbl install, no member frees; only calls `FUN_007b5be0` then optional free |
| 2 | This is a vector deleting dtor | **Falsified** — no array count / no `operator_delete[]`; single flags bit0 only |
| 3 | cdecl / stack this | **Falsified** — `8B F1`; vtbl thiscall dispatch |
| 4 | Always frees heap | **Falsified** — `test flags,1` / `jz` skips delete |
| 5 | Never frees heap | **Falsified** — bit0 path pushes this and calls `operator_delete` |
| 6 | Ghidra noreturn truncates / no return | **Falsified** — full 30 B reaches `MOV EAX,ESI; POP ESI; RET 4`; hex has `ADD ESP,4` |
| 7 | Same VA as complete dtor | **Falsified** — complete is `0x007b5be0` (493 B) |
| 8 | Not vtbl[0] | **Falsified** — dword @ `0x00a960ac` = `0x00423e50` |
| 9 | Name is skills-system product (not window) | **Falsified as class id** — RTTI `.?AVCNDUIWindow@@`; partition tag skills-abilities is residual ownership only |
| 10 | Named_CalleeOf scaffold still required | **Falsified** — meaningful product-class name sealed via RTTI + parent dual |
| 11 | ECX is flags / this on stack | **Falsified** — ESI←ECX; flags at `[ESP+8]` after push |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Scalar-deleting vs complete body | **High** | Double-free / miss free / wrong stack cleanup |
| flags bit0 gate | **High** | Leak or free non-heap this |
| RET 4 | **High** | Stack corruption on virtual call |
| CNDUIWindow family label | **High** | Wrong system map only |
| Product MSVC demangle of thunk | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + vtbl

```
// FUN_00423e50 (vtbl[0] of PTR_FUN_00a960ac):
push esi
mov  esi, ecx
call FUN_007b5be0          ; CNDUIWindow_CompleteDtor
test byte ptr [esp+8], 1
je   skip
push esi
call operator_delete       ; 0x00489822
add  esp, 4
skip:
mov  eax, esi
pop  esi
ret  4
```

Live decompile 2026-08-05 ≡ raw 2026-07-23 CF. Full-body hex seals all branches including `ADD ESP,4` omitted from false-noreturn disasm listing.  
Sibling pattern matches dualed `InventoryGrid_ScalarDeletingDtor` (same shape).  
Parent dual WQ9K-F already names complete body + points scalar peer to this VA.

---

## 4. Surviving contract for AutoCore

```
// Port scalar deleting only (not complete body):
void* CNDUIWindow_ScalarDeletingDtor(void* self, uint8_t flags) {
  CNDUIWindow_CompleteDtor(self);   // FUN_007b5be0 — separate unit
  if (flags & 1) operator_delete(self);
  return self;
}
// vtbl[0] of PTR_FUN_00a960ac; ret 4
// Do not inline complete body into this VA's port.
// Virtual delete: obj->vtbl[0](1) then null host pointer.
```

---

## 5. Verdict

All adversarial attacks on ABI/CF/vtbl/class identity fail. CNDUIWindow family is evidenced by RTTI + dualed complete/ctor install sites. **accept**.
