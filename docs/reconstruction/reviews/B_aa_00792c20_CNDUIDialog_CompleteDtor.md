# Review B (skeptical / adversarial): `aa_00792c20` CNDUIDialog_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00792c20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9K-G) |
| **Counterpart** | `reviews/A_aa_00792c20_CNDUIDialog_CompleteDtor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the scalar-deleting dtor | **Falsified** — no flags arg; no `operator_delete(this)`; scalar is `FUN_004280d0` |
| 2 | `operator_delete` at end frees host and never returns | **Falsified** — deletes **member** at `+0x4e0`; `ADD ESP,4`; zero slot; `CALL 007b5be0`; `RET` |
| 3 | Ghidra body end `00792ceb` is complete | **Falsified** — true end `00792d12` (243 B) |
| 4 | Installs CVOGMenu / CMenuChatlog / CWndTutorial vtbls | **Falsified** — only installs `00a98f44`; callers install derived first |
| 5 | Frees all six dwords from `[0x130]` contiguous | **Falsified** — skips `[0x131]` / `+0x4c4` |
| 6 | Product is only “NDUIContainerPanel” from ctor dual | **Falsified** — RTTI `.?AVCNDUIDialog@@`; ctor name residual |
| 7 | Vector-deleting form | **Falsified** — no count; no array loop |
| 8 | Leaf / no further base | **Falsified** — always chains `FUN_007b5be0` after EH −1 |
| 9 | Merge with `0082d540` as same class | **Falsified** — different RTTI, vtbl, size, callees |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Complete vs scalar | **High** | Double free / leak |
| Member-delete returns | **High** | Wrong tail / missing base dtor |
| Offset map + skip +0x4c4 | **High** | Use-after-free / leak |
| Vtbl install address | **High** | Wrong type identity |
| SEH epilogue | **High** | Stack imbalance |
| Product plate CNDUIDialog | **High** (RTTI) | Naming only if wrong |
| Slot English / deep base dual | **Open** | Nested teardown detail |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Scalar FUN_004280d0:
//   FUN_00792c20(this);
//   if (flags & 1) operator_delete(this);
// Intermediate FUN_0082d540:
//   *this = 00a72f6c; 0082ce20(); 00792c20();
// Tutorial complete 0097a8a0:
//   *this = 00a6f61c; 00792c20();  // direct
// Tail bytes @00792ce7:
//   CALL operator_delete; ADD ESP,4; MOV ECX,EDI; zero [ESI+4];
//   EH=-1; CALL 007b5be0; ADD ESP,0x10; RET
// RTTI: .?AVCNDUIDialog@@
```

Decompiler WARNING “does not return” is a **known false positive** for member free — bytes authority overrides.

---

## 4. Surviving contract for AutoCore

```
// Port as SHARED base complete dtor only:
void CNDUIDialog_CompleteDtor(CNDUIDialog* self) {
  self->vtbl = &PTR_FUN_00a98f44;
  FUN_007917c0(self);
  // scalar-delete owned: +0x4c0, +0x4c8..+0x4d8 (skip +0x4c4)
  // list clear at +0x4dc; free member +0x4e0 (not host)
  FUN_007b5be0(self);
  // scalar path deletes self if flags&1
}
// Do not treat operator_delete(+0x4e0) as noreturn free of host.
// Do not free this here.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/offsets/RTTI and **rejects decompiler tail / false-noreturn**. Residual slot English + deep base dual + runtime → **accept-with-gaps**.
