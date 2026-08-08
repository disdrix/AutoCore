# Review B (skeptical / adversarial): `aa_00511c00` StdTree_EraseAndRebalance_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00511c00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R12-015) |
| **Counterpart** | `reviews/A_aa_00511c00_StdTree_EraseAndRebalance_Isnil21_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is insert / rebalance-only | **Falsified** — throw on isnil iterator; unlinks node; `operator_delete`; size--; not insert twin `00511950` (`map/set too long` plate) |
| 2 | isnil@+0x29 / isnil29 family | **Falsified** — entry `80 78 21 00` (imm `0x21`); rotates are isnil21 duals not isnil29 |
| 3 | isnil@+0x2D / +0x31 family | **Falsified** — same imm seal; different peer VAs |
| 4 | Stack-arg only / `RET 0xC` (RetC family) | **Falsified** — `MOV EBX,ECX` thiscall; terminal `C2 08 00` RET 8 |
| 5 | Skill / ability product handler | **Falsified** — pure STL erase CF + `"invalid map/set<T> iterator"`; no skill strings; 0 product callers recovered |
| 6 | Leaf / no callees | **Falsified** — succ/min/max/L/R/delete/throw callees |
| 7 | Decomp "unreachable" two-child path is dead | **Falsified** — asm at `0x00511d1d` color-swap live |
| 8 | Function ends at `operator_delete` (noreturn) | **Falsified** — size-- / *outIt / `ret 8` continue after delete |
| 9 | Merge with isnil29 thiscall erase `004cb740` | **Falsified** — different isnil imm / rotates / value free plate |
| 10 | No value free (trivial value) | **Falsified** — free `[node+0x14]` if non-null; zero three dwords |
| 11 | Runtime Confirmed | **Rejected** — no Launcher; terminal false |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Erase + RB rebalance CF | **High** | Wrong tree mutation |
| ABI thiscall + RET 8 | **High** | Stack corruption |
| isnil@+0x21 | **High** | Wrong node family |
| Shared STL helper | **High** | Over-narrow skill port |
| Value heap @+0x14 identity | **Medium** | Wrong dtor for value_type |
| Product type English | **Low** | Naming only |
| Call graph inbound | **Low** | 0 xrefs — may be dead |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against parent + peers

```
// Parent dual R11-007 Rrotate isnil21 005a27f0:
//   this unit calls it ×3 in RB fixup; color@+0x20 isnil@+0x21 node 0x28
// R10-030 Lrotate isnil21 0050e9f0:
//   same family; called ×3 here
// Peer thiscall RET8 erase isnil29 004cb740:
//   same ABI shape (thiscall, outIt, node, ret 8); isnil imm 0x29; no +0x14 free
// Insert twin residual 00511950:
//   same SEH/isnil21 family; "map/set too long"; insert not erase
// Peer stack RET0xC erases 00402850 / 00408ed0:
//   different ABI; do not merge
```

---

## 4. Surviving contract for AutoCore

```
// Port as shared StdTree erase+rebalance for isnil@+0x21:
//  - thiscall; ECX = tree*; stack Node** outIt, Node* node; ret 8
//  - throw "invalid map/set<T> iterator" on isnil
//  - successor prep FUN_004e12c0; min 004cb2c0; max 00421a60
//  - if black: L 0050e9f0 / R 005a27f0
//  - free heap @ +0x14 if set; zero +0x14/+0x18/+0x1c; delete node; size--; *outIt
// Do not merge with isnil29/31 erases or RetC stack family.
// Do not treat as skill product logic.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/family/role. Product residual + zero callers → **accept-with-gaps**. Runtime Confirmed **not claimed**.
