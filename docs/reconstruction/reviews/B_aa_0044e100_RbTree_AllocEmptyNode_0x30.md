# Review B (skeptical / adversarial): `aa_0044e100` RbTree_AllocEmptyNode_0x30

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044e100` |
| **Review type** | Skeptical / adversarial (Path B) |
| **Date** | `2026-07-29` (W21-O) |
| **Counterpart** | `reviews/A_aa_0044e100_RbTree_AllocEmptyNode_0x30.md` |
| **Verdict** | **accept** on CF; reject overclaims about full map ctor / void return / self-linked empty tree |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function returns `void` / no useful result | **Falsified** — EAX = alloc; Profiler_Zone_Ctor / serialize assign result |
| 2 | This unit builds a complete empty `std::map` | **Falsified** — no self-links, no size field, no header object; only node seed |
| 3 | `+0x2c`/`+0x2d` product English guaranteed | **Overstated** — bytes sealed; color/isnil names **Probable** via MSVC + caller `+0x2d=1` |
| 4 | Null `operator_new` is safe | **Risk acknowledged** — if `eax==0`, lea/test paths may still touch low addresses; do not port as crash-proof OOM |
| 5 | Historical alias `Named_CalleeOf_…InitInstance` is product name | **Rejected** — scaffolding plate only |
| 6 | `puVar1+1 != NULL` is a meaningful heap check | **Artifact** — pointer arithmetic on non-null base is always non-null |
| 7 | Same as 0x18 factory except size | **Mostly true** — CF twin; flag offsets scale with size (`+0x14` vs `+0x2c`) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Size / flag offsets | **High** | Wrong node layout → tree corruption |
| EAX return | **High** | Leaked or dropped roots |
| Sentinel role via callers | **High** | Mis-port as general `new Node` with value ctor |
| Product naming | **Low–Tentative** | Docs only |
| OOM path | **Medium** | Rare crash on null new |
| Flag English (color/isnil) | **Probable** | Docs only if swapped |

---

## 3. Cross-check against caller `Profiler_Zone_Ctor` (`0x00786280`)

```
iVar1 = FUN_0044e100();
param_2[8] = iVar1;                 // head @ +0x20
*(iVar1 + 0x2d) = 1;                // isnil
*(iVar1 + 4) = iVar1;               // parent = self
*iVar1 = iVar1;                     // left = self
*(iVar1 + 8) = iVar1;               // right = self
param_2[9] = 0;                     // size
```

Therefore **empty-tree construction is split**: this VA allocates/seeds; init wrappers finish the header. Porting only `0044e100` as "create empty map" is **wrong**.

Note: Path A Profiler review earlier said nil `@head+0x2d=1` — **matches** caller write; factory leaves `+0x2d=0` then caller flips.

---

## 4. Surviving contract for AutoCore

```
node = RbTree_AllocEmptyNode_0x30():
  p = new(0x30)
  zero p[0], p[1], p[2]
  p.byte[0x2c] = 1
  p.byte[0x2d] = 0
  return p

// NOT done here:
//   self-links, size=0, header object, value construction
```

---

## 5. Open questions (narrow)

1. Node value_type for size `0x30` beyond sentinel use.
2. Whether any caller uses the node without setting `+0x2d=1`.
3. Live null-new path.

**Verdict:** **accept** on sealed CF + return + factory role; residual naming/OOM only.
