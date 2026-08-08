# Review B (skeptical / adversarial): `aa_0078ca80` CNDUIWndBuffered_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0078ca80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9K-F) |
| **Counterpart** | `reviews/A_aa_0078ca80_CNDUIWndBuffered_CompleteDtor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is only a scalar-deleting dtor | **Falsified** — no flags arg; installs vtbl; frees nested then base; no free of `this` |
| 2 | This is a vector-deleting dtor | **Falsified** — no array count / no `operator_delete[]` on host |
| 3 | cdecl / stack this | **Falsified** — entry `MOV ESI,ECX` |
| 4 | Frees host heap | **Falsified** — bare `RET`; host free is scalar peer `0x004293f0` only |
| 5 | Nested free skipped when null path only — field not always cleared | **Falsified** — store-zero of `+0x2A8` is after the if (unconditional) |
| 6 | Product class is CWndVehicle | **Falsified** — installs `00a99f74` not `00a6fbcc`; RTTI `.?AVCNDUIWndBuffered@@` |
| 7 | Same unit as CNDUIWindow complete | **Falsified** — this is intermediate layer; chains *into* `007b5be0` |
| 8 | Same unit as scalar `004293f0` | **Falsified** — scalar is thin complete-then-flags wrapper |
| 9 | Ctor twin is different class | **Falsified** — ctor `0078caf0` installs same vtbl + same RTTI |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Complete vs scalar/vector | **High** | Double-free / miss free |
| Vtbl + RTTI product name | **High** | Wrong base class port |
| Nested `+0x2A8` free-then-null | **High** | Leak / UAF |
| Base chain to CNDUIWindow | **High** | Incomplete teardown |
| Helper product English | **Open** | Residual only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + vtbl

```
// FUN_0078ca80 (CNDUIWndBuffered complete):
// SEH; ESI = ECX
mov  dword ptr [ESI], 00a99f74h
call FUN_007a8580
mov  ecx, esi
call FUN_0078c3d0
mov  ecx, [ESI+2A8h]
test ecx, ecx
jz   skip
mov  eax, [ecx]
push 1
call dword ptr [eax]
skip:
mov  dword ptr [ESI+2A8h], 0
call FUN_007b5be0
; SEH restore; ret
```

Live decompile 2026-08-05 ≡ raw CF.  
`read_memory` full 112 B sealed.  
COL `@0x00a99f70` → `0x00ab8280` → type_info `0x00afe4d0` → `.?AVCNDUIWndBuffered@@`.  
vtbl[0] dword `@0x00a99f74` = `0x004293f0` (scalar peer).

---

## 4. Surviving contract for AutoCore

```
// Port complete dtor only (not scalar):
void CNDUIWndBuffered_CompleteDtor(void* self) {
  *(void**)self = &PTR_FUN_00a99f74;
  FUN_007a8580(self);
  FUN_0078c3d0(self);
  void* nested = *(void**)((char*)self + 0x2A8);
  if (nested) { /* scalar-delete nested */ (*(void(***)(void*,int))nested)[0](nested, 1); }
  *(void**)((char*)self + 0x2A8) = nullptr; // always
  CNDUIWindow_CompleteDtor(self); // FUN_007b5be0
}
// Do NOT operator_delete(self) here.
// Scalar peer: 0x004293f0
```

---

## 5. Verdict

**accept-with-gaps** — adversarial probes on role/ABI/vtbl/RTTI/nested-path falsified; helper English remains open. Terminal **false**.
