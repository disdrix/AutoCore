# Review B (skeptical / adversarial): `aa_00457720` Class_00aa33a4_PlacementCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00457720` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W36-I) |
| **Counterpart** | `reviews/A_aa_00457720_Class_00aa33a4_PlacementCtor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-thiscall ctor (MSVC default) | **Falsified** — stack self, **`RET 4`**, no `MOV REG,ECX` for this |
| 2 | Function is void (Ghidra plate) | **Falsified** — `MOV EAX,ESI` returns self |
| 3 | Zeros entire 0x44 object | **Falsified** — only vtbl + three arrays; `+0x04…+0x13` untouched |
| 4 | Three arrays are the same type | **Falsified** — three distinct ctor/dtor pairs / vtbls (`00a9db18`, `00a9da80`, RefCountedPtr3Flags) |
| 5 | Count is dynamic / runtime | **Falsified** — immediate `push 2` / `push 8` each site |
| 6 | Same as NestedHash placement ctors | **Falsified** — different body, vtbl, layout; only ABI family (stack this, RET 4) shared |
| 7 | Multiple independent callers | **Falsified** — 1 xref (`0073c810` slot5) |
| 8 | `0096f530` elements are pointer-only RefCountedPtr | **Falsified** — W35-G sealed 3 flag bytes; distinct from `0096ef70` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| stack-this + RET 4 + return-this | **High** | Wrong ctor ABI |
| vtbl + three array sites | **High** | Wrong layout |
| span 0x44 | **High** | Wrong alloc size |
| element type distinction | **High** | Merged shells |
| Product class English | **Low** | Naming only |
| Unwritten head meaning | **Low** | Incomplete field map |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + callers

```
// Body hex end:
// 8B C6 64 89 0D 00 00 00 00 5E 83 C4 0C C2 04 00
// MOV EAX,ESI; restore FS; POP ESI; ADD ESP,0C; RET 4

// Offsets in body:
// LEA EAX,[ESI+0x14]  ; 8D 46 14
// LEA ECX,[ESI+0x24]  ; 8D 4E 24
// LEA EDX,[ESI+0x34]  ; 8D 56 34

// LAB_00437630 (element ctor, 16 B):
// 8B C1 C7 40 04 00 00 00 00 C7 00 80 DA A9 00 C3
// this→EAX; [this+4]=0; [this]=PTR_FUN_00a9da80; RET

// Sole caller: PUSH 0x44; operator_new; PUSH result; CALL FUN_00457720
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Full-body hex seals layout ladder.

---

## 4. Surviving contract for AutoCore

```
// Port as stack placement ctor, size 0x44:
struct Host_aa33a4 {
  void* vtbl;            // +0x00
  uint32_t unk04[4];     // +0x04 unwritten here
  Handle8 a[2];          // +0x14 vtbl 00a9db18
  Handle8 b[2];          // +0x24 vtbl 00a9da80
  RcPtr3Flags c[2];      // +0x34
};
Host_aa33a4* ctor(Host_aa33a4* self) {
  self->vtbl = &PTR_FUN_00aa33a4;
  vector_ctor(self->a, 2, ctor_a9db18, dtor_a9db18);
  vector_ctor(self->b, 2, ctor_a9da80, dtor_a9da80);
  vector_ctor(self->c, 2, RefCountedPtr3Flags_DefaultCtor, peer_dtor);
  return self;
}
// Do NOT use ECX-thiscall. Do NOT zero +0x04…+0x13 in this unit.
// Pair with HostPtrTable slot5 post-init FUN_00731130 (unowned).
```

---

## 5. Verdict

Adversarial pass confirms A on ABI, layout, three distinct element pairs, sole caller, span 0x44. Residuals product English + unwritten head + element product plates → **accept-with-gaps**.
