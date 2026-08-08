# Review B (skeptical / adversarial): `aa_004401b0` gfxUIWindow_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004401b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-129) |
| **Counterpart** | `reviews/A_aa_004401b0_gfxUIWindow_ScalarDeletingDtor.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the complete-object dtor body | **Falsified** — no vtbl install / member frees here; only calls `FUN_00759de0` then optional free |
| 2 | This is a vector deleting dtor | **Falsified** — no array count / no `operator_delete[]`; single flags bit0 only |
| 3 | cdecl / stack this | **Falsified** — entry `MOV ESI,ECX`; vtbl thiscall dispatch |
| 4 | Always frees heap | **Falsified** — `test flags,1` / `jz` skips delete |
| 5 | Never frees heap | **Falsified** — bit0 path pushes this and calls `operator_delete` |
| 6 | Ghidra noreturn truncates body | **Falsified** — full 30 B reaches `MOV EAX,ESI; POP ESI; RET 4` |
| 7 | Same unit as complete `00759de0` | **Falsified** — complete is 868 B bare-RET teardown; this is 30 B wrapper |
| 8 | Not vtbl[0] / not gfxUIWindow | **Falsified** — dword @ `00a9f304` = this VA; COL → `.?AVgfxUIWindow@@` |
| 9 | Product name is skills-abilities only | **Falsified as class** — RTTI is gfxUIWindow (UI); partition system tag is residual bucket only |
| 10 | Free path is `delete[]` / array | **Falsified** — scalar `operator_delete` @ `0x00489822`; no count arg |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Scalar-deleting vs complete body | **High** | Double-free / miss free / wrong stack cleanup |
| flags bit0 gate | **High** | Leak or free non-heap this |
| RET 4 | **High** | Stack corruption on virtual call |
| Product RTTI name | **High** | Naming residual closed |
| Complete dtor internals | **Open** (not owned) | Port must call, not inline |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + vtbl

```
// FUN_004401b0 (vtbl[0] of PTR_FUN_00a9f304 / gfxUIWindow):
push esi
mov  esi, ecx
call FUN_00759de0          ; complete body (thiscall)
test byte ptr [esp+8], 1
jz   skip
push esi
call operator_delete       ; 0x00489822
add  esp, 4
skip:
mov  eax, esi
pop  esi
ret  4
```

Live decompile 2026-08-05 ≡ raw 2026-07-23 CF. Full-body hex seals all branches.  
Sibling pattern matches dualed `CWndVehicle_ScalarDeletingDtor` (`0x004160d0`) and peer complete dual `aa_00759de0`.

RTTI:

```
*(u32*)0x00a9f300 = 0x00ab96a4   // COL ptr
*(u32*)0x00a9f304 = 0x004401b0   // vtbl[0] = this
COL.pTypeDescriptor = 0x00afe190
name = ".?AVgfxUIWindow@@"
```

---

## 4. Surviving contract for AutoCore

```
// Port scalar deleting only (not complete body):
void* gfxUIWindow_ScalarDeletingDtor(void* self, uint8_t flags) {
  gfxUIWindow_CompleteDtor(self);   // FUN_00759de0 — separate unit
  if (flags & 1) operator_delete(self);
  return self;
}
// vtbl[0] of PTR_FUN_00a9f304; ret 4
// Do not inline complete body into this VA's port.
```

---

## 5. Verdict

**accept** — adversarial probes falsified; sealed contract holds. Terminal **false**.
