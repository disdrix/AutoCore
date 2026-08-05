# Review B (skeptical / adversarial): `aa_00575350` Object_009d33c4_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00575350` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W28-M) |
| **Counterpart** | `reviews/A_aa_00575350_Object_009d33c4_CompleteDtor.md` |
| **Scratch** | `tmp/a_00575350.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is scalar deleting dtor | **Falsified** — no flags; no `delete this`; scalar is `FUN_00575c00` (vtbl[0]) |
| 2 | `FUN_00497360()` uses root this | **Falsified** — `LEA ECX,[ESI+0x1DC]` |
| 3 | CALL+RET to base (not tail) | **Falsified** — final `E9` jmp; pops restore before jmp |
| 4 | Not related to Object_SharedBase | **Falsified** — ctor twin calls `FUN_00518940`; tail to `FUN_00518ec0` |
| 5 | operator_delete is noreturn → truncated | **Falsified** — fall-through zeros + list + jmp sealed in 106 B |
| 6 | Same type as `Class_009c7a1c` | **Falsified** — different vtbl, layout, inheritance |
| 7 | Product type known | **Overstated** — structural Object-derived only |
| 8 | Vtbl[1] is real method | **Weak** — `FUN_0056f570` is empty RET stub (context only) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Derived complete dtor + tail base | **High** | Skip base teardown / double dtor |
| List @ +0x1DC | **High** | Wrong free |
| Owned + buffer offsets | **High** | Leak / UAF |
| Object_SharedBase parentage | **High** | Wrong port base |
| Product English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + caller

```
// FUN_00575c00 (vtbl[0]):
mov esi, ecx
call FUN_00575350   // body ends jmp base — returns from base to here
test flags, 1 → operator_delete(this)
ret 4
```

Note: scalar wrapper **CALL**s complete body; complete body **JMP**s base. Stack returns base → scalar → caller. Live decompile ≡ raw CF; bytes seal LEA + jmp.

---

## 4. Surviving contract for AutoCore

```
// Port complete dtor (not scalar wrapper):
Object_009d33c4_CompleteDtor(obj);
// 1) vtbl = PTR_FUN_009d33c4
// 2) free +0x1EC; clear +0x1F0/+0x1F1
// 3) free vector-like +0x1F8..+0x200
// 4) StdList_Destroy_FreeHead(obj+0x1DC)
// 5) Object shared-base dtor (FUN_00518ec0) on same this
// Do not skip base chain. Do not merge with Class_009c7a1c_CompleteDtor.
```

---

## 5. Verdict

Adversarial pass confirms A on inheritance chain, LEA list, and tail-jmp. Product name residual → **accept-with-gaps**.
