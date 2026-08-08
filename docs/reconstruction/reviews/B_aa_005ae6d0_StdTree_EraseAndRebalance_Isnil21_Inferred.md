# Review B (skeptical / adversarial): `aa_005ae6d0` StdTree_EraseAndRebalance_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae6d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R12-035) |
| **Counterpart** | `reviews/A_aa_005ae6d0_StdTree_EraseAndRebalance_Isnil21_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is insert / rebalance-only (no erase) | **Falsified** — `"invalid map/set<T> iterator"` + `operator_delete` + size--; insert twin is `00407200` |
| 2 | isnil@+0x29 / isnil29 family | **Falsified** — entry `80 78 21 00` (imm `0x21`); rotates are isnil21 `0050e9f0`/`005a27f0` not isnil29 |
| 3 | isnil@+0x19 Val12 family (adjacent `005ae990`) | **Falsified** — isnil imm `0x21` not `0x19`; different min/max/rotate callees |
| 4 | isnil@+0x31 family | **Falsified** — same imm seal; peer erase is `00408ed0` |
| 5 | Stack 3-arg / `RET 0xC` (RetC family) | **Falsified** — epilogue `C2 08 00`; call site only pushes 2 args + `MOV ECX,EDI` |
| 6 | cdecl / no this | **Falsified** — `MOV EBP,ECX` at entry; caller `MOV ECX,EDI` |
| 7 | `operator_delete` is true noreturn (no size--) | **Falsified** — bytes after delete: `test eax; jbe; add eax,-1; mov [ebp+8],eax` size-- then `*outIt` + `ret 8` |
| 8 | Skill / mission-product exclusive helper | **Falsified** — pure STL erase; sole caller is generic range erase `FUN_005af2e0`; family shared with insert/buynode/rotates |
| 9 | Same as range erase body | **Falsified** — range is `FUN_005af2e0` which **calls** this in a loop |
| 10 | Merge with isnil29 thiscall erase `004cb740` | **Falsified** — different isnil imm, rotates, min/max VAs |
| 11 | Runtime Confirmed | **Rejected** — Terminal false; no Launcher; dual does not claim runtime |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Erase + RB CF | **High** | Wrong container mutation |
| ABI thiscall + RET 8 | **High** | Stack corruption |
| isnil@+0x21 | **High** | Wrong node family |
| size-- epilogue | **High** | Leaked size accounting |
| Shared STL helper | **High** | Over-narrow port |
| Two-child splice detail | **Medium** | Edge-case tree shape |
| Product type English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against parent + peers

```
// Parent dual R11-007 Rrotate isnil21 005a27f0:
//   color@+0x20; isnil@+0x21; node 0x28; leaf rotate used by this erase
// R10-030 Lrotate isnil21 0050e9f0:
//   twin rotate; called from this erase fixup
// WQ9I-B InsertAndRebalance isnil21 00407200:
//   insert twin of this erase family
// Buynode Val16 isnil21 00408990 / empty 004088f0 Size0x28:
//   node size / value width seal
// Peer erase isnil29 thiscall 004cb740 / RetC 00402850:
//   same algorithm shape; different isnil imm + helper VAs
// Adjacent 005ae990 StdTree_EraseNode_Val12:
//   different family (isnil@+0x19); do not merge
// Sole caller 005af2e0:
//   range erase loop; MOV ECX,EDI seals thiscall
```

---

## 4. Surviving contract for AutoCore

```
// Port as shared StdTree single-node erase + RB rebalance for isnil@+0x21:
//  - thiscall; ECX = map*; stack Node** outIt, Node* node; ret 8
//  - nil → "invalid map/set<T> iterator" / DAT_00acc34c
//  - successor 004e12c0; min 004cb2c0; max 00421a60
//  - black fixup: L 0050e9f0 / R 005a27f0
//  - operator_delete; if size>0 size--; *outIt = succ
//  - color@+0x20; isnil@+0x21; node 0x28; Val16 @ +0x0C
// Pair with InsertAndRebalance 00407200, buynode 00408990, rotates.
// Do not merge with isnil29/31/Val12 erases or with range erase 005af2e0 body.
// Not Runtime Confirmed.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/family/role/epilogue. Product residual + two-child decomp gap → **accept-with-gaps**. Runtime Confirmed **not** claimed.
