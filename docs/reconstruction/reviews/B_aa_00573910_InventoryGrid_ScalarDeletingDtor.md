# Review B (skeptical / adversarial): `aa_00573910` InventoryGrid_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573910` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY WQ8R-E) |
| **Counterpart** | `reviews/A_aa_00573910_InventoryGrid_ScalarDeletingDtor.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the complete-object dtor body | **Falsified** — no vtbl install, no member frees; only calls `FUN_005725a0` then optional free |
| 2 | This is a vector deleting dtor | **Falsified** — no array count / no `operator_delete[]`; single flags bit0 only |
| 3 | cdecl / stack this | **Falsified** — `8B F1`; vtbl thiscall dispatch |
| 4 | Always frees heap | **Falsified** — `test flags,1` / `je` skips delete |
| 5 | Never frees heap | **Falsified** — bit0 path pushes this and calls `operator_delete` |
| 6 | Ghidra noreturn truncates | **Falsified** — full 29 B reaches `MOV EAX,ESI; POP ESI; RET 4` |
| 7 | Same VA as complete dtor | **Falsified** — complete is `0x005725a0` |
| 8 | Not vtbl[0] | **Falsified** — dword @ `0x009d3390` = `0x00573910` |
| 9 | Name is cargo-vehicle specific only | **Partially resisted** — destroy site is vehicle cargo, but vtbl is shared InventoryGrid family (ctor `0x00572650`); name InventoryGrid is correct scope |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Scalar-deleting vs complete body | **High** | Double-free / miss free / wrong stack cleanup |
| flags bit0 gate | **High** | Leak or free non-heap this |
| RET 4 | **High** | Stack corruption on virtual call |
| InventoryGrid family label | **High** | Wrong system map only |
| Product MSVC demangle | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + vtbl

```
// FUN_00573910 (vtbl[0] of PTR_FUN_009d3390):
push esi
mov  esi, ecx
call FUN_005725a0          ; complete body
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

Live decompile 2026-08-04 ≡ raw 2026-07-23 CF. Full-body hex seals all branches.  
Sibling pattern matches W31-E `Class_009c7938_ScalarDeletingDtor` (same 29 B shape).

---

## 4. Surviving contract for AutoCore

```
// Port scalar deleting only (not complete body):
void* InventoryGrid_ScalarDeletingDtor(void* self, uint8_t flags) {
  InventoryGrid_CompleteDtor(self);   // FUN_005725a0 — separate unit
  if (flags & 1) operator_delete(self);
  return self;
}
// vtbl[0] entry; ret 4
// Do not inline complete body into this VA's port.
// Cargo create path: if (grid) grid->vtbl[0](1); grid=null; before new grid.
```

---

## 5. Verdict

All adversarial attacks on ABI/CF/vtbl fail. InventoryGrid family is evidenced by ctor + parent dual. **accept**.
