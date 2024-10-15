module tierlist;
import <utility>;
import <algorithm>;

void TierList::swap(TierList &other) {
  std::swap(tiers, other.tiers);
  std::swap(tierCount, other.tierCount);
  std::swap(reserved, other.reserved);
}

void TierList::enlarge() {
  reserved = 2 + 2 * std::max(reserved, tierCount);
  List **newTiers = new List *[reserved];
  std::fill_n(newTiers, reserved, nullptr);
  std::copy_n(tiers, tierCount, newTiers);
  delete[] tiers;
  tiers = newTiers;
}

TierList::TierList() : tiers{nullptr}, tierCount{0}, reserved(0) {}
TierList::~TierList() {
  if (tiers) {
    for (size_t i = 0; i < tierCount; ++i) {
      delete tiers[i];
    }
  }
  delete[] tiers;
}

void TierList::push_back_tier() {
  // Need at least 1 extra as sentinel.
  if (tierCount + 1 >= reserved) {
    enlarge();
  }
  tiers[tierCount++] = new List;
}
void TierList::pop_back_tier() {
  if (tierCount > 0) {
    delete tiers[--tierCount];
    tiers[tierCount] = nullptr;
  }
}

void TierList::push_front_at_tier(size_t tier, const std::string &entry) {
  tiers[tier]->push_front(entry);
}
void TierList::pop_front_at_tier(size_t tier) {
  tiers[tier]->pop_front();
}

size_t TierList::tierSize() const { return tierCount; }
size_t TierList::size() const {
  size_t result = 0;
  for (size_t i = 0; i < tierCount; i++) {
    result += tiers[i]->size();
  }
  return result;
}

TierList::Iterator::Iterator(/* fill in appropriate parameters */){}

TierList::value_type TierList::Iterator::operator*() const {
}

TierList::Iterator &TierList::Iterator::operator++() {
}

TierList::Iterator TierList::Iterator::operator<<(int bk) const {
}

TierList::Iterator TierList::Iterator::operator>>(int fwd) const {
}

bool TierList::Iterator::operator!=(const Iterator &other) const {
}

TierList::Iterator TierList::begin() const {
}

TierList::Iterator TierList::end() const {
}

