# Review B (skeptical / adversarial): `aa_004293f0` CNDUIWndBuffered_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004293f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R10-009) |
| **Counterpart** | `reviews/A_aa_004293f0_CNDUIWndBuffered_ScalarDeletingDtor.md` |
| **Parent dual** | `0x0078ca80` `CNDUIWndBuffered_CompleteDtor` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the complete-object dtor body | **Falsified** — no vtbl install, no member frees, no SEH; only calls `FUN_0078ca80` then optional free |
| 2 | This is a vector deleting dtor | **Falsified** — no array count / no `operator_delete[]`; single flags bit0 only |
| 3 | cdecl / stack this | **Falsified** — `8B F1`; vtbl thiscall dispatch; parent installs this as vtbl[0] |
| 4 | Always frees heap | **Falsified** — `test flags,1` / `je` skips delete |
| 5 | Never frees heap | **Falsified** — bit0 path pushes this and calls `operator_delete` @ `0x00489822` |
| 6 | Ghidra noreturn truncates | **Falsified** — full 29 B reaches `MOV EAX,ESI; POP ESI; RET 4` |
| 7 | Same VA as complete dtor | **Falsified** — complete is `0x0078ca80` (112 B); this is free wrapper only |
| 8 | Not vtbl[0] | **Falsified** — dword @ `0x00a99f74` = `0x004293f0` (`read_memory`) |
| 9 | Product name invented / needs `_Inferred` | **Falsified** — parent dual sealed RTTI `.?AVCNDUIWndBuffered@@` + complete name `CNDUIWndBuffered_CompleteDtor`; scalar peer naming follows |
| 10 | Owns complete dtor logic | **Falsified** — complete body dualed under parent `aa_0078ca80` only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Scalar-deleting vs complete body | **High** | Double-free / miss free / wrong stack cleanup |
| flags bit0 gate | **High** | Leak or free non-heap this |
| RET 4 | **High** | Stack corruption on virtual call |
| Product class English | **High** (parent RTTI) | Naming only residual if parent wrong |
| Runtime | **Open** | Matrix policy; Terminal false |

---

## 3. Cross-check against raw + bytes + vtbl

```
// FUN_004293f0 (vtbl[0] of PTR_FUN_00a99f74):
push esi
mov  esi, ecx
call FUN_0078ca80          ; CNDUIWndBuffered_CompleteDtor
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

Live decompile 2026-08-05 ≡ raw 2026-07-23 CF. Full-body hex seals all branches.  
Parent dual ADV_wq9k already named free peer as `004293f0` only. Sibling pattern matches W31-E `Class_009c7938_ScalarDeletingDtor`.

---

## 4. Surviving contract for AutoCore

```
// Port scalar deleting only (not complete body):
void* CNDUIWndBuffered_ScalarDeletingDtor(void* self, uint8_t flags) {
  CNDUIWndBuffered_CompleteDtor(self);   // FUN_0078ca80 — separate unit
  if (flags & 1) operator_delete(self);
  return self;
}
// vtbl[0] entry of PTR_FUN_00a99f74; ret 4
// Do not inline complete body (vtbl install / +0x2A8 nested free / base CNDUIWindow) into this VA's port.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/vtbl/false-noreturn/product class. Residual gaps are parent ownership + runtime only → **accept**.
