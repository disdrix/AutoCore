# Review B (skeptical / adversarial): `aa_007917c0` CNDUIDialog_TeardownChildHash_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007917c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9L-I) |
| **Counterpart** | `reviews/A_aa_007917c0_CNDUIDialog_TeardownChildHash_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | cdecl / stack `this` | **Falsified** — `MOV EBP,ECX` at entry; no stack formal |
| 2 | This is the complete dtor of the dialog | **Falsified** — sole CALL from `FUN_00792c20` which continues scalar-deleting `+0x4c0`…`+0x136` and calls `FUN_00415e90` + `operator_delete` |
| 3 | Frees the hash object at `+0x4c0` | **Falsified** — `FUN_004281d0` is Recreate (BL=5); parent later `CALL [hash.vtbl](1)` |
| 4 | Frees `this` | **Falsified** — bare RET; parent owns host free |
| 5 | Product name is `VOG_DEBUG_STOP` | **Falsified** — that string is a HashError diagnostic path via `FUN_007a4480`; not RTTI |
| 6 | `FUN_004281d0` is free/delete | **Falsified** — EAX=hash, BL=5; family is HashError:Recreate |
| 7 | `FUN_00756be0` is thiscall on child only | **Falsified** — `MOV ECX,EBP` (dialog) + `PUSH ESI` (child) |
| 8 | Decompiler `FUN_004133c0(0)` is full ABI | **Falsified** — ESI=`this+0x4dc`, EAX=0, stack 0 (register ABI) |
| 9 | Product CNDUIDialog demangle sealed here | **Fails** — name from parent chain + HashError; no COL on this leaf → `_Inferred` |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX=this, bare RET, void | **High** | Wrong ABI / stack smash |
| +0x4c0 hash / +0x4b8 helper / +0x4c4 flag / +0x4dc shell | **High** | Wrong teardown fields |
| Hash lock +0x1d / chain +0x14 / value +8 | **High** | Walk corruption |
| Recreate not free | **High** | Double-free or leak misport |
| Sole CALL from complete dtor | **High** | Mis-attribute lifecycle |
| Vtbl English (+0x3c0 etc.) | **Med** | Naming only |
| Product class demangle | **Open** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check

```text
// Parent sole CALL site (assembly authority @ 0x00792c4d):
//   MOV EDI, ECX
//   MOV [EDI], 0xa98f44          // install complete-dtor vtbl
//   CALL 0x007917c0              // OWN leaf — teardown children under hash
//   MOV ECX, [EDI+0x4c0]
//   CMP ECX, 0 / JZ skip
//   PUSH 1; CALL [EAX]           // scalar-delete hash AFTER leaf returns
// Matches: leaf clears/recreates; parent frees pointer.
//
// HashError strings (live PUSH immediates):
//   0xa27cd0 "HashError:TraversalLock, already locked for traversal"
//   0xa27c9c "HashError:TraverseToNext, not locked for traversal"
//   0xa15844 "VOG_DEBUG_STOP"
```

A ≡ B on live decompile + full disasm + entry/exit hex + parent assembly_context.

---

## 4. Surviving contract for AutoCore

```text
// Port as CNDUIDialog child-hash teardown leaf (not complete dtor):
// - ECX = this; bare RET; void
// - if hash@+0x4c0 null: return
// - clear selection (vtbl+0x3c0(0)); release helper@+0x4b8
// - lock hash; walk chain; nested optional teardown; child release;
//   zero child+0x2b0; erase from dialog vector (FUN_00756be0)
// - unlock; clear list shell@+0x4dc; recreate empty hash (width log2=5)
// - set flag@+0x4c4 = 1
// Do not free this or hash*; do not merge with complete dtor 00792c20;
// do not invent product demangle; keep HashError diagnostics.
```

---

## 5. Verdict

Adversarial pass confirms A's ABI, offset map, Recreate-not-free, and parent lifecycle split. Rejects complete-dtor merge / free-hash / VOG_DEBUG_STOP product-name / decompiler-hidden register ABI overclaims. Residual product demangle + vtbl English → **accept-with-gaps**.
